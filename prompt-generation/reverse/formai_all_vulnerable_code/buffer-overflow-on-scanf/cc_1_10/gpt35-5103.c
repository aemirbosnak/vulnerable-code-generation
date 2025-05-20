//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_DB_SIZE 1000
#define MAX_STR_LENGTH 100

pthread_mutex_t lock; // mutex lock to protect shared resource

// structure for each record in the database
typedef struct Record {
    char name[MAX_STR_LENGTH];
    int age;
    float salary;
} Record;

Record database[MAX_DB_SIZE]; // the database
int num_records = 0; // number of records in database

// helper function to print a record
void print_record(Record* record) {
    printf("Name: %s\nAge: %d\nSalary: %.2f\n", record->name, record->age, record->salary);
}

// thread function to add a record to the database
void* add_record(void* args) {
    pthread_mutex_lock(&lock); // acquire mutex lock
    
    // read input from user
    Record record;
    printf("Enter name, age, and salary (separated by spaces):\n");
    scanf("%s %d %f", record.name, &record.age, &record.salary);
    
    // add record to database
    database[num_records] = record;
    num_records++;
    
    printf("Record added successfully!\n");
    
    pthread_mutex_unlock(&lock); // release mutex lock
    
    pthread_exit(NULL); // exit thread
}

// thread function to search for a record in the database
void* search_record(void* args) {
    pthread_mutex_lock(&lock); // acquire mutex lock
    
    // read input from user
    char name[MAX_STR_LENGTH];
    printf("Enter name to search:\n");
    scanf("%s", name);
    
    // search for record in database
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Record found:\n");
            print_record(&database[i]);
            pthread_mutex_unlock(&lock); // release mutex lock
            pthread_exit(NULL); // exit thread
        }
    }
    
    printf("Record not found!\n");
    
    pthread_mutex_unlock(&lock); // release mutex lock
    
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_mutex_init(&lock, NULL); // initialize mutex lock
    
    while (1) {
        // get user input
        printf("Enter 1 to add a record, 2 to search for a record, or 3 to exit:\n");
        int choice;
        scanf("%d", &choice);
        
        // create thread based on user choice
        pthread_t thread;
        switch (choice) {
            case 1:
                pthread_create(&thread, NULL, add_record, NULL);
                break;
            case 2:
                pthread_create(&thread, NULL, search_record, NULL);
                break;
            case 3:
                pthread_mutex_destroy(&lock); // destroy mutex lock
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                continue;
        }
        
        pthread_join(thread, NULL); // wait for thread to complete
    }
    
    return 0;
}