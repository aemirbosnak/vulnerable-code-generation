//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DANCERS 100
#define MIN_MUSIC_LEN 10
#define MAX_MUSIC_LEN 50

struct Dancer {
    char name[50];
    int age;
    struct Dancer *next;
};

void Dance(struct Dancer **head, char *music) {
    printf("\n%s\n", music);
    struct Dancer *current = *head;
    while (current != NULL) {
        printf("\nDancer: %s, Age: %d, Dancing!\n", current->name, current->age);
        sleep(1);
        current = current->next;
    }
}

void CreateDancers(struct Dancer **head) {
    *head = NULL;
    int i;
    for (i = 0; i < MAX_DANCERS; i++) {
        struct Dancer *newDancer = (struct Dancer *) malloc(sizeof(struct Dancer));
        if (newDancer == NULL) {
            printf("Memory allocation failed! Exiting...\n");
            free(*head);
            exit(1);
        }
        printf("\nCreating dancer #%d\n", i + 1);
        scanf("%s", newDancer->name);
        newDancer->age = rand() % 100;
        newDancer->next = *head;
        *head = newDancer;
    }
}

int main() {
    int choice;
    char music[MAX_MUSIC_LEN];
    struct Dancer *head = NULL;

    while (1) {
        printf("\nWelcome to the Memory_Dance party!\n");
        printf("\n1. Create dancers\n");
        printf("\n2. Dance\n");
        printf("\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCreating dancers...\n");
                CreateDancers(&head);
                break;
            case 2:
                printf("\nEnter some music for the dance (min. %d characters, max. %d characters):\n", MIN_MUSIC_LEN, MAX_MUSIC_LEN);
                scanf("%s", music);
                Dance(&head, music);
                break;
            case 3:
                printf("\nThank you for joining the Memory_Dance party! See you next time!\n");
                free(head);
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}