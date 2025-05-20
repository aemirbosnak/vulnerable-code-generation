//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char name[20];
    int age;
    char gender;
} Person;

void print_person(Person p) {
    printf("%s (%d years old, %c gender)\n", p.name, p.age, p.gender);
}

Person create_person(char* name, int age, char gender) {
    Person p;
    strcpy(p.name, name);
    p.age = age;
    p.gender = gender;
    return p;
}

int main() {
    Person romeo, juliet;
    char romeo_name[MAX_LEN], juliet_name[MAX_LEN];
    int romeo_age, juliet_age;
    char romeo_gender, juliet_gender;

    printf("Enter Romeo's name: ");
    scanf("%s", romeo_name);
    printf("Enter Romeo's age: ");
    scanf("%d", &romeo_age);
    printf("Enter Romeo's gender (M/F): ");
    scanf(" %c", &romeo_gender);

    romeo = create_person(romeo_name, romeo_age, romeo_gender);

    printf("Enter Juliet's name: ");
    scanf("%s", juliet_name);
    printf("Enter Juliet's age: ");
    scanf("%d", &juliet_age);
    printf("Enter Juliet's gender (M/F): ");
    scanf(" %c", &juliet_gender);

    juliet = create_person(juliet_name, juliet_age, juliet_gender);

    printf("\n--- ROMEO AND JULIET ---");
    printf("\nRomeo: ");
    print_person(romeo);
    printf("\nJuliet: ");
    print_person(juliet);

    if (romeo.age > juliet.age) {
        printf("\nRomeo is older than Juliet.\n");
    } else if (romeo.age < juliet.age) {
        printf("\nJuliet is older than Romeo.\n");
    } else {
        printf("\nThey are the same age.\n");
    }

    if (strcmp(romeo.name, juliet.name) > 0) {
        printf("\nRomeo's name comes after Juliet's in the alphabet.\n");
    } else {
        printf("\nJuliet's name comes before Romeo's in the alphabet.\n");
    }

    if (romeo.gender == juliet.gender) {
        printf("\nRomeo and Juliet are of the same gender.\n");
    } else {
        printf("\nRomeo and Juliet are of different genders.\n");
    }

    return 0;
}