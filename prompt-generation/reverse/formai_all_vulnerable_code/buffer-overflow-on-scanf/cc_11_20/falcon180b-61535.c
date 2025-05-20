//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/sem.h>

#define TRUE 1
#define FALSE 0
#define MAX 10

typedef struct {
    int id;
    char name[20];
    int status;
} person;

person people[MAX];

int main() {
    int i, n, choice, status;
    char ch;
    key_t key;
    int shmid, semid;
    int *shmptr;
    struct sembuf sem_op;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the name and id of person %d:\n", i+1);
        scanf("%s%d", people[i].name, &people[i].id);
    }

    srand(getpid());
    for(i=0; i<n; i++) {
        people[i].status = rand()%2;
    }

    for(i=0; i<n; i++) {
        printf("Person %s is %s\n", people[i].name, people[i].status==0?"available":"busy");
    }

    while(1) {
        printf("Enter your choice:\n");
        printf("1. View status\n");
        printf("2. Send message\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(i=0; i<n; i++) {
                    printf("Person %s is %s\n", people[i].name, people[i].status==0?"available":"busy");
                }
                break;
            case 2:
                printf("Enter the id of person to send message: ");
                scanf("%d", &n);
                if(people[n-1].status==0) {
                    printf("Sorry, %s is not available\n", people[n-1].name);
                }
                else {
                    printf("Enter your message for %s:\n", people[n-1].name);
                    scanf("%s", people[n-1].name);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}