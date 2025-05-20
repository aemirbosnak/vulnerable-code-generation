//LLAMA2-13B DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct person p1, p2;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];
    int age1, age2;

    // Ask for the first person's name and age
    printf("Enter the first person's name: ");
    fgets(name1, MAX_NAME_LENGTH, stdin);
    printf("Enter the first person's age: ");
    scanf("%d", &age1);

    // Create the first person
    strcpy(p1.name, name1);
    p1.age = age1;

    // Ask for the second person's name and age
    printf("Enter the second person's name: ");
    fgets(name2, MAX_NAME_LENGTH, stdin);
    printf("Enter the second person's age: ");
    scanf("%d", &age2);

    // Create the second person
    strcpy(p2.name, name2);
    p2.age = age2;

    // Print the two people's information
    printf("The first person is: %s, %d years old.\n", p1.name, p1.age);
    printf("The second person is: %s, %d years old.\n", p2.name, p2.age);

    // Calculate and print the difference between the two ages
    int age_diff = abs(p2.age - p1.age);
    printf("The difference between the two ages is: %d years.\n", age_diff);

    // Print a message based on the age difference
    if (age_diff < 10) {
        printf("The two people are close in age! ");
    } else if (age_diff < 20) {
        printf("The two people are within a decade of each other! ");
    } else {
        printf("The two people are from different generations! ");
    }

    return 0;
}