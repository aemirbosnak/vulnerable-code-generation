//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_CHARS];
    int age;
    char title[MAX_CHARS];
} Knight;

void append_entry(FILE *file, Knight knight) {
    fseek(file, 0, SEEK_END);
    fwrite(&knight, sizeof(Knight), 1, file);
}

void list_entries(FILE *file) {
    Knight knight;
    fseek(file, 0, SEEK_SET);
    printf("\nList of Valorous Knights:\n");
    printf("------------------------------------------------\n");
    printf("Name\t\t\tAge\tTitle\n");
    printf("------------------------------------------------\n");
    
    while (fread(&knight, sizeof(Knight), 1, file) == 1) {
        printf("%-20s\t%d\t%s\n", knight.name, knight.age, knight.title);
    }
}

void search_entry(FILE *file, const char *name) {
    Knight knight;
    fseek(file, 0, SEEK_SET);
    
    while (fread(&knight, sizeof(Knight), 1, file) == 1) {
        if (strcmp(knight.name, name) == 0) {
            printf("\nFound Knight:\n");
            printf("Name: %s, Age: %d, Title: %s\n", knight.name, knight.age, knight.title);
            return;
        }
    }
    printf("\nNo knight found with the name \"%s\".\n", name);
}

int main() {
    FILE *file;
    Knight knight;
    int choice;
    char search_name[MAX_CHARS];
    
    file = fopen("knights.dat", "ab+");
    if (file == NULL) {
        fprintf(stderr, "The warlock could not open the noble file!\n");
        exit(1);
    }
    
    while (1) {
        printf("\n=== Kingdom of File Handling ===\n");
        printf("1. Add Knight\n");
        printf("2. List Knights\n");
        printf("3. Search Knight\n");
        printf("4. Exit\n");
        printf("=================================\n");
        printf("Choose thy fate (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name of the knight: ");
                scanf(" %[^\n]%*c", knight.name);
                printf("Enter age of the knight: ");
                scanf("%d", &knight.age);
                printf("Enter the title of the knight: ");
                scanf(" %[^\n]%*c", knight.title);
                append_entry(file, knight);
                printf("\nThe valor of the knight hath been recorded!\n");
                break;
            case 2:
                list_entries(file);
                break;
            case 3:
                printf("Enter the name of the knight to search: ");
                scanf(" %[^\n]%*c", search_name);
                search_entry(file, search_name);
                break;
            case 4:
                fclose(file);
                printf("Farewell, brave scribe! Till the next parchment...\n");
                exit(0);
            default:
                printf("Thou hast chosen unwisely! Please choose a valid option.\n");
        }
    }
    
    fclose(file);
    return 0;
}