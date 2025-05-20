//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is my favorite function. It's like a magic spell!
void backup_files(char *source, char *dest) {
    // Let's open the source file like a treasure chest!
    FILE *src = fopen(source, "r");
    if (src == NULL) {
        printf("Oh no! I can't find the source file. It's like a lost sock!\n");
        return;
    }

    // Now, let's create a new chest to store our backup.
    FILE *dst = fopen(dest, "w");
    if (dst == NULL) {
        printf("Oops! I can't create the backup file. It's like a broken toy!\n");
        fclose(src);
        return;
    }

    // It's time to copy the contents of the treasure chest!
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src) != NULL) {
        // Let's write the treasure into the new chest!
        fputs(buffer, dst);
    }

    // Yay! We've successfully backed up our files! Let's give ourselves a high-five!
    printf("Hooray! I've backed up your files like a superhero!\n");

    // Now, let's close our treasure chests properly.
    fclose(src);
    fclose(dst);
}

int main() {
    // Let's gather the secrets we want to keep safe.
    char source[100];
    char dest[100];

    printf("Hey there, my trusty sidekick! What's the secret file you want to backup?\n");
    scanf("%s", source);

    printf("Excellent! Now, where should I stash this treasure?\n");
    scanf("%s", dest);

    // It's showtime! Let's perform the backup magic!
    backup_files(source, dest);

    return 0;
}