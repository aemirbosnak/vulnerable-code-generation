//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int room[10]; //10 rooms in the hotel

void *occupy(void *arg){
    int *room_no = (int *)arg;
    if(room[*room_no]==0){ //if room is vacant
        room[*room_no] = pthread_self(); //thread id to this room
        printf("Room %d has been occupied by thread %ld\n", *room_no+1, pthread_self());
    }else{ //if room is already occupied
        printf("Room %d is already occupied\n", *room_no+1);
    }
    pthread_exit(NULL);
}

void *free_room(void *arg){
    int *room_no = (int *)arg;
    if(room[*room_no]==pthread_self()){ //if thread id is already in this room
        room[*room_no] = 0; //free the room
        printf("Room %d has been freed by thread %ld\n", *room_no+1, pthread_self());
    }else{ //if thread id is not in this room
        printf("Thread %ld did not occupy Room %d\n", pthread_self(), *room_no+1);
    }
    pthread_exit(NULL);
}

int main(){
    int i, n, choice;
    pthread_t tid; //thread id
    for(i=0; i<10; i++){
        room[i] = 0; //initializing all rooms as vacant
    }
    while(1){ //infinite loop
        printf("\n\nEnter your choice:\n");
        printf("1. Occupy Room\n");
        printf("2. Free Room\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: //occupy room
                printf("\nEnter the room number: ");
                scanf("%d", &n);
                pthread_create(&tid, NULL, occupy, &n); //create a thread for occupying room
                pthread_join(tid, NULL); //wait for thread to finish
                break;
            case 2: //free room
                printf("\nEnter the room number: ");
                scanf("%d", &n);
                pthread_create(&tid, NULL, free_room, &n); //create a thread for freeing room
                pthread_join(tid, NULL); //wait for thread to finish
                break;
            case 3: //exit
                printf("\nExiting Program...\n");
                exit(0);
            default: //invalid choice
                printf("\nInvalid choice. Try again...\n");
        }
    }
    return 0;
}