//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
} item;

item items[MAX_ITEMS];
int num_items = 0;

void add_item(char* name, float amount) {
    strcpy(items[num_items].name, name);
    items[num_items].amount = amount;
    num_items++;
}

void remove_item(int index) {
    if (index >= 0 && index < num_items) {
        num_items--;
        for (int i = index; i < num_items; i++) {
            strcpy(items[i].name, items[i+1].name);
            items[i].amount = items[i+1].amount;
        }
    }
}

void print_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].amount);
    }
}

void save_items(char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not save items to file.\n");
        return;
    }
    for (int i = 0; i < num_items; i++) {
        fprintf(file, "%s - $%.2f\n", items[i].name, items[i].amount);
    }
    fclose(file);
}

void load_items(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not load items from file.\n");
        return;
    }
    char line[MAX_NAME_LEN];
    while (fgets(line, MAX_NAME_LEN, file)!= NULL) {
        add_item(line, 0.0);
    }
    fclose(file);
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");
    char input[MAX_NAME_LEN];
    while (1) {
        printf("Enter an item name and amount (or type'save' to save or 'load' to load items):\n");
        scanf("%s", input);
        if (strcmp(input, "save") == 0) {
            char filename[MAX_NAME_LEN];
            printf("Enter a filename to save items to:\n");
            scanf("%s", filename);
            save_items(filename);
        } else if (strcmp(input, "load") == 0) {
            char filename[MAX_NAME_LEN];
            printf("Enter a filename to load items from:\n");
            scanf("%s", filename);
            load_items(filename);
        } else {
            float amount;
            sscanf(input, "%s - $%.2f", items[num_items].name, &amount);
            add_item(items[num_items].name, amount);
        }
        print_items();
    }
    return 0;
}