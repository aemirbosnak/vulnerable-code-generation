//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
} Person;

typedef struct {
    int id;
    int *friends;
    int num_friends;
} Friendship;

int main() {
    // Create some people
    Person people[] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Carol"},
        {4, "Dave"},
        {5, "Eve"},
    };

    // Create some friendships
    Friendship friendships[] = {
        {1, (int[]){2, 3}, 2},
        {2, (int[]){1, 4}, 2},
        {3, (int[]){1, 5}, 2},
        {4, (int[]){2, 5}, 2},
        {5, (int[]){3, 4}, 2},
    };

    // Print the people
    printf("People:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %d - %s\n", people[i].id, people[i].name);
    }

    // Print the friendships
    printf("Friendships:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %d - %s", friendships[i].id, people[friendships[i].friends[0]].name);
        for (int j = 1; j < friendships[i].num_friends; j++) {
            printf(", %s", people[friendships[i].friends[j]].name);
        }
        printf("\n");
    }

    return 0;
}