//Falcon-180B DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int height;
    int weight;
} Person;

int main() {
    Person *people = NULL;
    int count = 0;
    int choice;

    do {
        printf("\n");
        printf("1. Add a person\n");
        printf("2. Display all people\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count >= MAX_SIZE) {
                    printf("Maximum number of people reached.\n");
                    break;
                }
                people = (Person*)realloc(people, sizeof(Person) * (count+1));
                if(people == NULL) {
                    printf("Memory error.\n");
                    exit(1);
                }
                people[count].name = (char*)malloc(sizeof(char) * 50);
                if(people[count].name == NULL) {
                    printf("Memory error.\n");
                    exit(1);
                }
                printf("Enter name: ");
                scanf("%s", people[count].name);
                printf("Enter age: ");
                scanf("%d", &people[count].age);
                printf("Enter height: ");
                scanf("%d", &people[count].height);
                printf("Enter weight: ");
                scanf("%d", &people[count].weight);
                count++;
                break;
            case 2:
                for(int i=0; i<count; i++) {
                    printf("Name: %s\n", people[i].name);
                    printf("Age: %d\n", people[i].age);
                    printf("Height: %d\n", people[i].height);
                    printf("Weight: %d\n", people[i].weight);
                    printf("\n");
                }
                break;
            case 3:
                for(int i=0; i<count; i++) {
                    free(people[i].name);
                }
                free(people);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

    } while(1);

    return 0;
}