//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 10000

typedef struct {
    int id;
    char name[50];
    char email[50];
    char address[100];
    char phone[20];
} Data;

void print_data(Data *data) {
    printf("ID: %d\n", data->id);
    printf("Name: %s\n", data->name);
    printf("Email: %s\n", data->email);
    printf("Address: %s\n", data->address);
    printf("Phone: %s\n", data->phone);
}

void read_data(Data *data, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter data for record %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &data[i].id);
        printf("Name: ");
        scanf("%s", data[i].name);
        printf("Email: ");
        scanf("%s", data[i].email);
        printf("Address: ");
        scanf("%s", data[i].address);
        printf("Phone: ");
        scanf("%s", data[i].phone);
    }
}

void filter_data(Data *data, int size, char *query) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(data[i].name, query)) {
            count++;
            print_data(&data[i]);
        }
    }
    printf("Found %d matching records.\n", count);
}

int main() {
    Data data[MAX_DATA_SIZE];
    int size;
    char query[50];

    printf("Enter the number of records: ");
    scanf("%d", &size);
    read_data(data, size);

    printf("Enter the query string: ");
    scanf("%s", query);
    filter_data(data, size, query);

    return 0;
}