//FormAI DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Knight {
    char name[20], rank[10], weapon[20];
    int strength, defense;
};

void addKnight(FILE *fp) {
    struct Knight new_knight;
    printf("Enter name of the knight: ");
    scanf("%s", new_knight.name);
    printf("Enter rank of the knight: ");
    scanf("%s", new_knight.rank);
    printf("Enter weapon of the knight: ");
    scanf("%s", new_knight.weapon);
    printf("Enter strength of the knight: ");
    scanf("%d", &new_knight.strength);
    printf("Enter defense of the knight: ");
    scanf("%d", &new_knight.defense);
    fprintf(fp, "%s %s %s %d %d\n", new_knight.name, new_knight.rank, new_knight.weapon, new_knight.strength, new_knight.defense);
}

void listKnights(FILE *fp) {
    printf("Knight Name\t\tRank\t\tWeapon\t\tStrength\tDefense\n");
    printf("=================================================================\n");
    struct Knight knight;
    while(fscanf(fp, "%s %s %s %d %d\n", knight.name, knight.rank, knight.weapon, &knight.strength, &knight.defense) != EOF) {
        printf("%-20s%-15s%-15s%-15d%-10d\n", knight.name, knight.rank, knight.weapon, knight.strength, knight.defense);
    }
    printf("\n");
}

void searchKnight(FILE *fp) {
    char name[20];
    printf("Enter the name of the knight to be searched: ");
    scanf("%s", name);
    struct Knight knight;
    int found = 0;
    while(fscanf(fp, "%s %s %s %d %d\n", knight.name, knight.rank, knight.weapon, &knight.strength, &knight.defense) != EOF) {
        if(strcmp(name, knight.name) == 0) {
            printf("Knight found!\n");
            printf("Knight Name\t\tRank\t\tWeapon\t\tStrength\tDefense\n");
            printf("=================================================================\n");
            printf("%-20s%-15s%-15s%-15d%-10d\n", knight.name, knight.rank, knight.weapon, knight.strength, knight.defense);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Knight not found!\n");
    }
}

int main() {
    FILE *fp;
    fp = fopen("knights.txt", "a+");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int option;
    do {
        printf("Choose an option:\n1. Add a new knight\n2. List all knights\n3. Search for a knight\n4. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addKnight(fp);
                printf("Knight added successfully!\n");
                break;
            case 2:
                listKnights(fp);
                break;
            case 3:
                searchKnight(fp);
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(option != 4);

    fclose(fp);
    return 0;
}