//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void backupFile(char* filename) {
    // pretend to backup the file
    printf("Backing up %s...\n", filename);
    printf("Copying and pasting the code into a new file...\n");
    printf("Adding some comments to make it look like I did something...\n");
}

int main() {
    // generate a random file name
    srand(time(NULL));
    int randNum = rand() % 1000;
    char filename[15];
    sprintf(filename, "file%d.c", randNum);

    // create the file
    FILE *fp;
    fp = fopen(filename, "w");
    fprintf(fp, "#include<stdio.h>\n");
    fprintf(fp, "int main() {\n");
    fprintf(fp, "    printf(\"Hello, World!\\n\");\n");
    fprintf(fp, "    return 0;\n");
    fprintf(fp, "}");

    // pretend to compile the file
    printf("Compiling %s...\n", filename);
    printf("Adding some warnings just to make it look more impressive...\n");
    printf("1 warning generated. Please don't worry about it.\n");

    // pretend to run the file
    printf("Running %s...\n", filename);
    printf("Hello, World!\n");

    // pretend to backup the file
    printf("Do you want to backup the file? (y/n): ");
    char answer;
    scanf("%c", &answer);
    if (answer == 'y') {
        backupFile(filename);
    }

    // pretend to delete the file
    printf("Deleting %s...\n", filename);
    printf("Are you sure you want to delete this amazing code? (y/n): ");
    scanf("%c", &answer);
    if (answer == 'y') {
        remove(filename);
        printf("File successfully deleted :( \n");
    } else {
        printf("Good choice! Enjoy your new masterpiece.\n");
    }

    return 0;
}