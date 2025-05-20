//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRIENDS 5
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int age;
} Friend;

void createFriends(Friend **friends, int *count) {
    *count = 0;
    *friends = (Friend *)malloc(MAX_FRIENDS * sizeof(Friend));
    if (*friends == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Let's make some friends! You can have up to %d friends.\n", MAX_FRIENDS);
    
    for (int i = 0; i < MAX_FRIENDS; i++) {
        printf("Friend %d:\n", i + 1);
        printf("Enter name: ");
        fgets((*friends)[i].name, NAME_LENGTH, stdin);
        (*friends)[i].name[strcspn((*friends)[i].name, "\n")] = '\0'; // Remove newline
        
        printf("Enter age: ");
        scanf("%d", &(*friends)[i].age);
        getchar(); // Clear the newline from input buffer

        (*count)++;

        char more;
        if (i < MAX_FRIENDS - 1) {
            printf("Do you want to add another friend? (y/n): ");
            scanf(" %c", &more);
            getchar(); // Clear the newline from input buffer

            if (more != 'y') {
                break;
            }
        }
    }
    printf("You have created %d friends!\n", *count);
}

void displayFriends(Friend *friends, int count) {
    printf("\nHere's the list of your friends:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s, Age: %d\n", i + 1, friends[i].name, friends[i].age);
    }
}

void freeMemory(Friend *friends) {
    free(friends);
    printf("Memory has been freed. Goodbye friends! :)\n");
}

int main() {
    Friend *friends = NULL;
    int count = 0;

    createFriends(&friends, &count);
    displayFriends(friends, count);
    
    freeMemory(friends);

    return 0;
}