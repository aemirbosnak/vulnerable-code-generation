//FormAI DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    int age;
    char name[20];
    char occupation[20];
};

int main() {
    struct Person people[5];
    int i, j;
    char input[20];
    
    //Prompt user for input
    printf("Enter the age, name, and occupation for 5 people:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d%s%s", &people[i].age, people[i].name, people[i].occupation);
    }
    
    //Data mining - Find the oldest person
    int oldest = people[0].age;
    char oldest_name[20];
    for (i = 1; i < 5; i++) {
        if (people[i].age > oldest) {
            oldest = people[i].age;
            strcpy(oldest_name, people[i].name);
        }
    }
    printf("\n%s is the oldest person at %d years old.\n", oldest_name, oldest);
    
    //Data mining - Count the number of unique occupations
    int unique_count = 0; //initialize count to 0
    char unique_occupations[5][20]; //array to store unique occupations
    for (i = 0; i < 5; i++) {
        for (j = 0; j < unique_count; j++) {
            if (strcmp(people[i].occupation, unique_occupations[j]) == 0) {
                break; //occupation already counted
            }
        }
        if (j == unique_count) { //new occupation found
            strcpy(unique_occupations[unique_count], people[i].occupation);
            unique_count++;
        }
    }
    printf("\nThere are %d unique occupations:", unique_count);
    for (i = 0; i < unique_count; i++) {
        printf(" %s", unique_occupations[i]);
    }
    printf("\n");
    
    return 0;
}