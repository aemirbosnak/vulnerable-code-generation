//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct knight {
    int id;
    char name[25];
    int age;
};

struct knight knights[10];

int main() {
    // Seed the random number generator
    srand(time(0));

    // Initialize the database
    for(int i=0; i<10; i++) {
        knights[i].id = i+1;
        sprintf(knights[i].name, "Knight%d", i+1);
        knights[i].age = rand()%50 + 20;
    }

    // Print the knights database
    printf("Knights Database:\n");
    printf("ID   Name               Age\n");
    printf("----------------------------\n");
    for(int i=0; i<10; i++) {
        printf("%d    %-18s %d\n", knights[i].id, knights[i].name, knights[i].age);
    }

    // Add a new knight to the database
    struct knight new_knight;
    printf("\nEnter the details of the new knight:\n");
    printf("Name: ");
    scanf("%s", new_knight.name);
    new_knight.id = knights[9].id + 1;
    new_knight.age = rand()%50 + 20;
    knights[9] = new_knight;

    // Print the updated knights database
    printf("\nUpdated Knights Database:\n");
    printf("ID   Name               Age\n");
    printf("----------------------------\n");
    for(int i=0; i<10; i++) {
        printf("%d    %-18s %d\n", knights[i].id, knights[i].name, knights[i].age);
    }

    return 0;
}