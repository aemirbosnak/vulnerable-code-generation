//Falcon-180B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_SIZE 1000
#define MAX_STRING_SIZE 50

typedef struct {
    int id;
    char name[MAX_STRING_SIZE];
    int age;
    char gender[MAX_STRING_SIZE];
} Data;

void read_data(Data *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter data for record %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &data[i].id);
        printf("Name: ");
        scanf("%s", data[i].name);
        printf("Age: ");
        scanf("%d", &data[i].age);
        printf("Gender: ");
        scanf("%s", data[i].gender);
    }
}

void print_data(Data *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("Record %d:\n", i+1);
        printf("ID: %d\n", data[i].id);
        printf("Name: %s\n", data[i].name);
        printf("Age: %d\n", data[i].age);
        printf("Gender: %s\n", data[i].gender);
        printf("\n");
    }
}

void calculate_average_age(Data *data, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i].age;
    }
    double avg_age = (double)sum / n;
    printf("Average age: %.2f\n", avg_age);
}

void count_gender(Data *data, int n, char *gender) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].gender, gender) == 0) {
            count++;
        }
    }
    printf("Number of %s: %d\n", gender, count);
}

int main() {
    int n;
    printf("Enter number of records: ");
    scanf("%d", &n);

    Data data[MAX_DATA_SIZE];
    if (n > MAX_DATA_SIZE) {
        printf("Error: Maximum number of records is %d.\n", MAX_DATA_SIZE);
        return 1;
    }

    read_data(data, n);
    print_data(data, n);

    calculate_average_age(data, n);

    char gender[MAX_STRING_SIZE];
    printf("Enter gender to count: ");
    scanf("%s", gender);
    count_gender(data, n, gender);

    return 0;
}