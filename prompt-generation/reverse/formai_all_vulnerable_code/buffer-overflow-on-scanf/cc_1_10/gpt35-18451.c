//FormAI DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char name[20];
    int age;
    float height;
} Person;

void add_person(Person people[], int *count);
void list_people(Person people[], int count);
void save_people(Person people[], int count);
int load_people(Person people[]);

int main() {
    Person people[MAX_RECORDS];
    int count = 0;
    char choice;

    count = load_people(people);

    do {
        printf("\n");
        printf("1) Add person\n");
        printf("2) List people\n");
        printf("3) Save people\n");
        printf("4) Quit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_person(people, &count);
                break;
            case '2':
                list_people(people, count);
                break;
            case '3':
                save_people(people, count);
                break;
            case '4':
                printf("Quitting\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        // clear input buffer
        while ((getchar()) != '\n');

    } while (choice != '4');

    return 0;
}

void add_person(Person people[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Max records reached\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", people[*count].name);

    printf("Enter age: ");
    scanf("%d", &people[*count].age);

    printf("Enter height: ");
    scanf("%f", &people[*count].height);

    (*count)++;
}

void list_people(Person people[], int count) {
    if (count == 0) {
        printf("No records found\n");
        return;
    }
    
    printf("%-20s %-10s %-10s\n", "Name", "Age", "Height");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f\n", people[i].name, people[i].age, people[i].height);
    }
}

void save_people(Person people[], int count) {
    FILE *fp;
    fp = fopen("people.dat", "wb");

    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    fwrite(&count, sizeof(count), 1, fp);

    for (int i = 0; i < count; i++) {
        fwrite(&people[i], sizeof(Person), 1, fp);
    }

    fclose(fp);

    printf("Saved %d records\n", count);
}

int load_people(Person people[]) {
    FILE *fp;
    int count;

    fp = fopen("people.dat", "rb");

    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return 0;
    }

    fread(&count, sizeof(count), 1, fp);

    for (int i = 0; i < count; i++) {
        fread(&people[i], sizeof(Person), 1, fp);
    }

    fclose(fp);

    return count;
}