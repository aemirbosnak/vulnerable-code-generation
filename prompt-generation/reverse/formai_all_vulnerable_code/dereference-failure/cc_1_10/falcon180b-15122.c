//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

//Task structure
struct Task{
    int id;
    void (*func)();
    struct Task* next;
};

//Linked list of tasks
struct Task* head = NULL;

//Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Add a new task to the end of the list
void addTask(int id, void (*func)()){
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    newTask->id = id;
    newTask->func = func;
    newTask->next = NULL;

    if(head == NULL){
        head = newTask;
    }
    else{
        struct Task* temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

//Remove a task from the list
void removeTask(int id){
    if(head == NULL){
        return;
    }

    if(head->id == id){
        struct Task* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Task* temp = head;
    while(temp->next!= NULL){
        if(temp->next->id == id){
            struct Task* node = temp->next;
            temp->next = temp->next->next;
            free(node);
            return;
        }
        temp = temp->next;
    }
}

//Execute all tasks in the list
void executeTasks(){
    pthread_mutex_lock(&mutex);

    struct Task* temp = head;
    while(temp!= NULL){
        (*temp->func)();
        temp = temp->next;
    }

    pthread_mutex_unlock(&mutex);
}

//Function to be executed as a task
void task1(){
    printf("Task 1 executed\n");
}

//Function to be executed as a task
void task2(){
    printf("Task 2 executed\n");
}

//Main function
int main(){
    //Add tasks
    addTask(1, task1);
    addTask(2, task2);

    //Execute tasks after 5 seconds
    sleep(5);
    executeTasks();

    //Remove tasks
    removeTask(1);
    removeTask(2);

    return 0;
}