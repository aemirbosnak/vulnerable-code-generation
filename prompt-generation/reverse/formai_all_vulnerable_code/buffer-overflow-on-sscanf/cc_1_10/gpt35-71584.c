//FormAI DATASET v1.0 Category: File system simulation ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_FILES 100 // Maximum number of files in the system
#define MAX_FILENAME_LEN 20 // Maximum length of a filename
#define MAX_FILESIZE 1000 // Maximum size of a file in bytes

// Define a struct to represent a file
struct File {
    char name[MAX_FILENAME_LEN];
    char contents[MAX_FILESIZE];
    int size;
};

// Define a struct to represent the file system
struct FileSystem {
    struct File files[MAX_FILES];
    int num_files;
} medieval_filesystem;

// Function to create a new file
void create_file(char *name) {
    // Check if there is already a file with this name
    for (int i = 0; i < medieval_filesystem.num_files; i++) {
        if (strcmp(name, medieval_filesystem.files[i].name) == 0) {
            printf("$ %s already exists.\n", name);
            return;
        }
    }
    
    // Create the new file
    struct File newfile;
    strcpy(newfile.name, name);
    strcpy(newfile.contents, "");
    newfile.size = 0;
    
    // Add the file to the file system
    medieval_filesystem.files[medieval_filesystem.num_files] = newfile;
    medieval_filesystem.num_files++;
    
    printf("$ %s created.\n", name);
}

// Function to delete a file
void delete_file(char *name) {
    // Check if there is a file with this name
    int index = -1;
    for (int i = 0; i < medieval_filesystem.num_files; i++) {
        if (strcmp(name, medieval_filesystem.files[i].name) == 0) {
            index = i;
            break;
        }
    }
    
    // If there is no file with this name, return an error message
    if (index == -1) {
        printf("$ %s not found.\n", name);
        return;
    }
    
    // Otherwise, delete the file and shift all subsequent files back by one index
    for (int i = index; i < medieval_filesystem.num_files - 1; i++) {
        medieval_filesystem.files[i] = medieval_filesystem.files[i+1];
    }
    
    medieval_filesystem.num_files--;
    
    printf("$ %s deleted.\n", name);
}

// Function to write to a file
void write_file(char *name, char *contents) {
    // Check if there is a file with this name
    int index = -1;
    for (int i = 0; i < medieval_filesystem.num_files; i++) {
        if (strcmp(name, medieval_filesystem.files[i].name) == 0) {
            index = i;
            break;
        }
    }
    
    // If there is no file with this name, return an error message
    if (index == -1) {
        printf("$ %s not found.\n", name);
        return;
    }
    
    // Otherwise, write the contents to the file
    strcpy(medieval_filesystem.files[index].contents, contents);
    medieval_filesystem.files[index].size = strlen(contents);
    
    printf("$ %s written to %s.\n", contents, name);
}

// Function to read a file
void read_file(char *name) {
    // Check if there is a file with this name
    int index = -1;
    for (int i = 0; i < medieval_filesystem.num_files; i++) {
        if (strcmp(name, medieval_filesystem.files[i].name) == 0) {
            index = i;
            break;
        }
    }
    
    // If there is no file with this name, return an error message
    if (index == -1) {
        printf("$ %s not found.\n", name);
        return;
    }
    
    // Otherwise, print out the contents of the file
    printf("$ %s\n", medieval_filesystem.files[index].contents);
}

// The main function
int main() {
    medieval_filesystem.num_files = 0;
    
    printf("Welcome to the Medieval File System!\n");
    
    // Run the shell indefinitely
    while (1) {
        // Print the prompt
        printf("> ");
        
        // Read a line of input from the user
        char input[100];
        fgets(input, 100, stdin);
        
        // Parse the input and execute the appropriate command
        char command[20];
        char name[MAX_FILENAME_LEN];
        char contents[MAX_FILESIZE];
        sscanf(input, "%s %s %[^\n]s", command, name, contents);
        
        if (strcmp(command, "create") == 0) {
            create_file(name);
        } else if (strcmp(command, "delete") == 0) {
            delete_file(name);
        } else if (strcmp(command, "write") == 0) {
            write_file(name, contents);
        } else if (strcmp(command, "read") == 0) {
            read_file(name);
        } else {
            printf("$ Invalid command.\n");
        }
    }
    
    return 0;
}