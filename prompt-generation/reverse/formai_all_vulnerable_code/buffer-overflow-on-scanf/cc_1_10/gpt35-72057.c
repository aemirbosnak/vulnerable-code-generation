//FormAI DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    int num_people;
    printf("How many people do you want to enter? ");
    scanf("%d", &num_people);

    struct Person *people = (struct Person*) malloc(num_people * sizeof(struct Person));

    for(int i=0; i<num_people; i++) {
        printf("\nPerson %d\n", i+1);
        printf("Name: ");
        scanf("%s", people[i].name);
        printf("Age: ");
        scanf("%d", &people[i].age);
        printf("Height (in meters): ");
        scanf("%f", &people[i].height);
    }

    // Print the data sorted by age
    printf("\nSorted by age:\n");
    for(int i=0; i<num_people-1; i++) {
        for(int j=i+1; j<num_people; j++) {
            if(people[i].age > people[j].age) {
                struct Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
    for(int i=0; i<num_people; i++) {
        printf("%s, %d, %.2f meters tall\n", people[i].name, people[i].age, people[i].height);
    }

    // Print the data sorted by name
    printf("\nSorted by name:\n");
    for(int i=0; i<num_people-1; i++) {
        for(int j=i+1; j<num_people; j++) {
            if(strcmp(people[i].name, people[j].name) > 0) {
                struct Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
    for(int i=0; i<num_people; i++) {
        printf("%s, %d, %.2f meters tall\n", people[i].name, people[i].age, people[i].height);
    }

    free(people);
    return 0;
}