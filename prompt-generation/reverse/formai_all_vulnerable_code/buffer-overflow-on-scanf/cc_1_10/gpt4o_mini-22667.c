//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int isRecovered;
} File;

void poetic_intro() {
    printf("In the realm of lost files and forgotten dreams,\n");
    printf("We embark on a quest among digital streams.\n");
    printf("To recover what once was, and bring back the light,\n");
    printf("Let us traverse through shadows, into a world so bright.\n");
    printf("\n");
}

void show_files(File files[], int num_files) {
    printf("Here lies a tapestry of digital treasures:\n");
    for (int i = 0; i < num_files; i++) {
        printf(" - %s%s\n", files[i].filename,
               files[i].isRecovered ? " (Recovered)" : "");
    }
    printf("\n");
}

void recover_file(File *file) {
    if (!file->isRecovered) {
        file->isRecovered = 1;
        printf("Ah, sweet %s has been recovered, back in my embrace!\n", file->filename);
    } else {
        printf("%s was never lost, just hidden in the heart's database.\n", file->filename);
    }
}

void end_poem() {
    printf("\nAs the sun sets on our quest, I take a bow,\n");
    printf("For every file found, a promise to vow.\n");
    printf("Technology’s magic, though complex and grand,\n");
    printf("In the realm of lost data, love will always withstand.\n");
}

int main() {
    poetic_intro();
    
    File files[MAX_FILES] = {
        {"sweet_memory.txt", 0},
        {"longing_heart.mp3", 0},
        {"faded_photos.jpg", 0},
        {"forgotten_dream.log", 0},
        {"wanderlust_doc.docx", 0}
    };
    
    int num_files = 5;
    char choice[MAX_FILENAME_LENGTH];
    
    while (1) {
        show_files(files, num_files);
        printf("Which file would you like to recover? (or type 'exit' to leave): ");
        scanf("%s", choice);
        
        if (strcmp(choice, "exit") == 0) {
            printf("Fare thee well, my dear friend. Until our paths cross again...\n");
            break;
        }
        
        int found = 0;
        for (int i = 0; i < num_files; i++) {
            if (strcmp(files[i].filename, choice) == 0) {
                recover_file(&files[i]);
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("Oh, how my heart aches! I cannot find the file named %s.\n", choice);
        }
        
        printf("\n");
    }

    end_poem();
    return 0;
}