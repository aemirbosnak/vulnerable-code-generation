//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>

// struct to hold details of a person
struct Person {
    char name[20];
    int age;
    char gender[10];
};

// function to search for a person by name
int search_by_name(struct Person people[], int num_people, char search_name[]) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, search_name) == 0) {
            return i;
        }
    }
    return -1;
}

// function to search for a person by age
int search_by_age(struct Person people[], int num_people, int search_age) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (people[i].age == search_age) {
            return i;
        }
    }
    return -1;
}

// function to search for a person by gender
int search_by_gender(struct Person people[], int num_people, char search_gender[]) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].gender, search_gender) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int num_people = 5;
    struct Person people[num_people];

    // populate the people array
    strcpy(people[0].name, "John");
    people[0].age = 28;
    strcpy(people[0].gender, "male");

    strcpy(people[1].name, "Mary");
    people[1].age = 24;
    strcpy(people[1].gender, "female");

    strcpy(people[2].name, "David");
    people[2].age = 31;
    strcpy(people[2].gender, "male");

    strcpy(people[3].name, "Lisa");
    people[3].age = 27;
    strcpy(people[3].gender, "female");

    strcpy(people[4].name, "Tom");
    people[4].age = 25;
    strcpy(people[4].gender, "male");

    // perform searches
    char search_name[20];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    int index = search_by_name(people, num_people, search_name);
    if (index == -1) {
        printf("%s not found\n", search_name);
    } else {
        printf("%s found at index %d\n", search_name, index);
    }

    int search_age;
    printf("Enter age to search: ");
    scanf("%d", &search_age);
    index = search_by_age(people, num_people, search_age);
    if (index == -1) {
        printf("People with age %d not found\n", search_age);
    } else {
        printf("People with age %d found at index %d\n", search_age, index);
    }

    char search_gender[10];
    printf("Enter gender to search: ");
    scanf("%s", search_gender);
    index = search_by_gender(people, num_people, search_gender);
    if (index == -1) {
        printf("People with gender %s not found\n", search_gender);
    } else {
        printf("People with gender %s found at index %d\n", search_gender, index);
    }

    return 0;
}