//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a data structure to hold information about a person
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Function to read data from a file and store it in an array of Person structures
void read_data_from_file(Person *people, int num_people, FILE *file) {
    int i;
    for (i = 0; i < num_people; i++) {
        fscanf(file, "%s %d %f\n", people[i].name, &people[i].age, &people[i].height);
    }
}

// Function to sort an array of Person structures by age
void sort_people_by_age(Person *people, int num_people) {
    int i, j;
    Person temp;
    for (i = 0; i < num_people-1; i++) {
        for (j = i+1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

// Function to print an array of Person structures
void print_people(Person *people, int num_people) {
    int i;
    for (i = 0; i < num_people; i++) {
        printf("%s %d %f\n", people[i].name, people[i].age, people[i].height);
    }
}

// Main function
int main() {
    FILE *file;
    Person people[1000];
    int num_people;

    // Open the input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read the data from the file
    num_people = 0;
    while (fscanf(file, "%s %d %f\n", people[num_people].name, &people[num_people].age, &people[num_people].height)!= EOF) {
        num_people++;
    }
    fclose(file);

    // Sort the data by age
    sort_people_by_age(people, num_people);

    // Print the sorted data
    printf("Sorted data:\n");
    print_people(people, num_people);

    return 0;
}