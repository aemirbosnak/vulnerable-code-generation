//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[20];
    int age;
    int weight;
    int height;
    int steps;
} fitness_entry;

int main() {
    fitness_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    do {
        printf("Fitness Tracker\n");
        printf("1. Add a new entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_entries >= MAX_ENTRIES) {
                    printf("Maximum entries reached.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", entries[num_entries].name);
                    printf("Enter age: ");
                    scanf("%d", &entries[num_entries].age);
                    printf("Enter weight: ");
                    scanf("%d", &entries[num_entries].weight);
                    printf("Enter height: ");
                    scanf("%d", &entries[num_entries].height);
                    printf("Enter steps: ");
                    scanf("%d", &entries[num_entries].steps);
                    num_entries++;
                }
                break;

            case 2:
                if(num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("Name\tAge\tWeight\tHeight\tSteps\n");
                    for(int i = 0; i < num_entries; i++) {
                        printf("%s\t%d\t%d\t%d\t%d\n", entries[i].name, entries[i].age, entries[i].weight, entries[i].height, entries[i].steps);
                    }
                }
                break;

            case 3:
                printf("Enter name to search: ");
                char search_name[20];
                scanf("%s", search_name);
                int found = 0;
                for(int i = 0; i < num_entries; i++) {
                    if(strcmp(entries[i].name, search_name) == 0) {
                        printf("Name: %s\nAge: %d\nWeight: %d\nHeight: %d\nSteps: %d\n", entries[i].name, entries[i].age, entries[i].weight, entries[i].height, entries[i].steps);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Entry not found.\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}