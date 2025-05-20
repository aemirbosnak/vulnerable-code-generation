//Falcon-180B DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char gender[10];
} Person;

int main() {
    FILE *fp;
    Person people[100];
    int count = 0;

    // Open the database file for reading
    fp = fopen("database.txt", "r");
    if (fp == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    // Read the data from the database file and store it in an array
    while (fscanf(fp, "%s %d %s\n", people[count].name, &people[count].age, people[count].gender)!= EOF) {
        count++;
    }

    // Close the database file
    fclose(fp);

    // Display the data in a formatted table
    printf("Name\tAge\tGender\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].gender);
    }

    // Sort the data by age in ascending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Display the sorted data in a formatted table
    printf("\nName\tAge\tGender\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].gender);
    }

    // Filter the data by gender
    char gender[10];
    printf("\nEnter the gender to filter by: ");
    scanf("%s", gender);
    count = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].gender, gender) == 0) {
            printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].gender);
        }
    }

    return 0;
}