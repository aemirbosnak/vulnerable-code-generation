//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define FILE_NAME_LEN 20
#define BUFFER_SIZE 256

typedef struct {
    char name[FILE_NAME_LEN];
    char content[BUFFER_SIZE];
    int size;
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
} FileSystem;

void init_file_system(FileSystem *fs) {
    fs->file_count = 0;
    printf("Welcome to the Magical File System of Wonders! 🎩✨\n");
}

void create_file(FileSystem *fs) {
    if (fs->file_count >= MAX_FILES) {
        printf("Oops! You've hit the file limit! No more files allowed! 🚫\n");
        return;
    }

    File new_file;
    printf("Enter the name of the file (max 20 characters): ");
    scanf("%s", new_file.name);
    printf("Enter the content of the file (max 256 characters): ");
    getchar(); // consume newline
    fgets(new_file.content, BUFFER_SIZE, stdin);
    
    new_file.size = strlen(new_file.content);
    fs->files[fs->file_count++] = new_file;
    
    printf("File '%s' created with magic! 🪄\n", new_file.name);
}

void list_files(FileSystem *fs) {
    if (fs->file_count == 0) {
        printf("No files found in the mystical realm! 📜👻\n");
        return;
    }
    
    printf("Here are the treasures you possess:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("- %s (Size: %d bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

void read_file(FileSystem *fs) {
    char filename[FILE_NAME_LEN];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("Content of '%s':\n", fs->files[i].name);
            printf("%s\n", fs->files[i].content);
            return;
        }
    }
    
    printf("Alas! The file '%s' does not exist! 🥺📚\n", filename);
}

void delete_file(FileSystem *fs) {
    char filename[FILE_NAME_LEN];
    printf("Enter the name of the file to delete: ");
    scanf("%s", filename);
    
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->file_count--;
            printf("The file '%s' has been magically erased! ✨🪄\n", filename);
            return;
        }
    }
    
    printf("Can't find the file '%s'! Did it run away? 😱\n", filename);
}

void display_menu() {
    printf("\nMagical File System Menu:\n");
    printf("1. Create a file\n");
    printf("2. List all files\n");
    printf("3. Read a file\n");
    printf("4. Delete a file\n");
    printf("5. Exit the realm\n");
}

int main() {
    FileSystem fs;
    init_file_system(&fs);

    while (1) {
        display_menu();
        int choice;
        printf("Choose your destiny (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_file(&fs);
                break;
            case 2:
                list_files(&fs);
                break;
            case 3:
                read_file(&fs);
                break;
            case 4:
                delete_file(&fs);
                break;
            case 5:
                printf("Thank you for visiting the Magical File System! Bye-bye! 🎉👋\n");
                exit(0);
            default:
                printf("That's not a valid choice! Consult the Oracle for better options! 🤔🔮\n");
        }
    }

    return 0;
}