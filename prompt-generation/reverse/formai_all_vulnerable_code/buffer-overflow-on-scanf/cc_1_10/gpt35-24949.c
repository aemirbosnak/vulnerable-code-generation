//FormAI DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100
#define MAX_NAME 32
#define MAX_AGE 3

struct record {
    char name[MAX_NAME];
    int age;
    int salary;
};

typedef struct record Record;

void print_records(Record *data, int count);

int main()
{
    Record data[MAX_DATA];
    int count = 0;
    char choice = 'y';

    while (choice == 'y') {
        printf("Enter the name: ");
        scanf("%s", data[count].name);

        printf("Enter the age: ");
        scanf("%d", &data[count].age);

        printf("Enter the salary: ");
        scanf("%d", &data[count].salary);

        count++;
        printf("Do you want to enter more records? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\nData entered by the user:\n");
    print_records(data, count);

    printf("\nData sorted by age in ascending order:\n");

    //Bubble sort algorithm
    Record temp;
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j].age > data[j+1].age) {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    print_records(data, count);

    return 0;
}

void print_records(Record *data, int count)
{
    printf("\nName\tAge\tSalary\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%d\n", data[i].name, data[i].age, data[i].salary);
    }
}