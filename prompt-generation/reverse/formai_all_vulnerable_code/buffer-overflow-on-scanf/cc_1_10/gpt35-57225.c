//FormAI DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* filename;
    time_t timestamp;
} file;

int main() {
    int num_files;
    printf("How many files do you want to backup? ");
    scanf("%d", &num_files);

    file* files = malloc(sizeof(file) * num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file #%d: ", i + 1);
        char name[50];
        scanf("%s", name);
        files[i].filename = malloc(sizeof(char) * 50);
        strcpy(files[i].filename, name);

        files[i].timestamp = time(NULL);
        printf("%s backed up at %s", files[i].filename, asctime(localtime(&files[i].timestamp)));
    }

    printf("Would you like to restore a backup? (y/n) ");
    char response;
    scanf(" %c", &response);

    if (response == 'y') {
        int backup_num;
        printf("Which backup would you like to restore? (#1 - #%d): ", num_files);
        scanf("%d", &backup_num);

        if (backup_num <= num_files && backup_num >= 1) {
            printf("%s restored at %s", files[backup_num - 1].filename, asctime(localtime(&files[backup_num - 1].timestamp)));
        } else {
            printf("Invalid backup number.");
        }
    } else {
        printf("Goodbye!");
    }

    for (int i = 0; i < num_files; i++) {
        free(files[i].filename);
    }
    free(files);

    return 0;
}