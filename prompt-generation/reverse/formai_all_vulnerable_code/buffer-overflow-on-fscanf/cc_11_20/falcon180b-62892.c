//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    char address[MAX_SIZE];
} Person;

int main() {
    FILE* file;
    Person people[MAX_SIZE];
    int num_people = 0;
    char choice;

    file = fopen("people.txt", "r");
    if(file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while(fscanf(file, "%s %d %s", people[num_people].name, &people[num_people].age, people[num_people].address)!= EOF) {
        num_people++;
    }

    fclose(file);

    int search_age;
    char search_name[MAX_SIZE];

    do {
        printf("Enter 1 to search by name\n");
        printf("Enter 2 to search by age\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name to search for:\n");
                scanf("%s", search_name);
                for(int i = 0; i < num_people; i++) {
                    if(strcmp(people[i].name, search_name) == 0) {
                        printf("Found %s, age %d, address %s\n", people[i].name, people[i].age, people[i].address);
                    }
                }
                break;
            case 2:
                printf("Enter age to search for:\n");
                scanf("%d", &search_age);
                for(int i = 0; i < num_people; i++) {
                    if(people[i].age == search_age) {
                        printf("Found %s, age %d, address %s\n", people[i].name, people[i].age, people[i].address);
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 3);

    return 0;
}