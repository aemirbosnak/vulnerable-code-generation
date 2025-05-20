//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MUSIC_NUMBER 100
#define MAX_MUSIC_NAME_LEN 50

typedef struct music {
    char name[MAX_MUSIC_NAME_LEN];
    int num;
} Music;

Music library[MAX_MUSIC_NUMBER];
int music_num = 0;

void add_music() {
    char name[MAX_MUSIC_NAME_LEN];
    printf("Enter music name: ");
    scanf("%s", name);

    for (int i = 0; i < music_num; i++) {
        if (strcmp(library[i].name, name) == 0) {
            printf("Music %s already exists.\n", name);
            return;
        }
    }

    printf("Enter music number: ");
    scanf("%d", &library[music_num].num);
    strcpy(library[music_num].name, name);
    music_num++;
}

void delete_music() {
    char name[MAX_MUSIC_NAME_LEN];
    printf("Enter music name: ");
    scanf("%s", name);

    for (int i = 0; i < music_num; i++) {
        if (strcmp(library[i].name, name) == 0) {
            for (int j = i; j < music_num - 1; j++) {
                strcpy(library[j].name, library[j + 1].name);
                library[j].num = library[j + 1].num;
            }
            music_num--;
            break;
        }
    }
}

void search_music() {
    char name[MAX_MUSIC_NAME_LEN];
    printf("Enter music name: ");
    scanf("%s", name);

    for (int i = 0; i < music_num; i++) {
        if (strcmp(library[i].name, name) == 0) {
            printf("Music %s, number: %d\n", library[i].name, library[i].num);
        }
    }
}

void display_music() {
    for (int i = 0; i < music_num; i++) {
        printf("Music %s, number: %d\n", library[i].name, library[i].num);
    }
}

int main() {
    int choice;

    do {
        printf("\nMusic Library Management System\n");
        printf("1. Add music\n2. Delete music\n3. Search music\n4. Display all music\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_music();
                break;
            case 2:
                delete_music();
                break;
            case 3:
                search_music();
                break;
            case 4:
                display_music();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}