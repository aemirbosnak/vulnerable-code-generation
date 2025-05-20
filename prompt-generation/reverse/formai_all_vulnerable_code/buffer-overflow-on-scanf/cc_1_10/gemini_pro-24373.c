//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Welcome message
void welcome() {
    printf("Welcome to the CyberBackup Matrix, choomba.\n");
    printf("Where your data is safe from the clutches of the corps.\n");
}

// Get file size
long get_file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

// Read file into buffer
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    
    long size = get_file_size(file);
    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        fclose(file);
        return NULL;
    }
    
    fread(buffer, size, 1, file);
    fclose(file);
    buffer[size] = '\0';
    return buffer;
}

// Write buffer to file
int write_file(const char *filename, char *buffer, long size) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    fwrite(buffer, size, 1, file);
    fclose(file);
    return 0;
}

// Generate random string
char *generate_random_string(int length) {
    char *string = malloc(length + 1);
    if (string == NULL) {
        perror("Error allocating string");
        return NULL;
    }
    
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        string[i] = (char)('a' + rand() % 26);
    }
    string[length] = '\0';
    return string;
}

// Backup file
int backup_file(const char *filename) {
    char *buffer = read_file(filename);
    if (buffer == NULL) {
        return -1;
    }
    
    long size = get_file_size(filename);
    char *random_string = generate_random_string(16);
    char *backup_filename = malloc(strlen(filename) + strlen(random_string) + 1);
    if (backup_filename == NULL) {
        perror("Error allocating backup filename");
        free(buffer);
        return -1;
    }
    
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".");
    strcat(backup_filename, random_string);
    int result = write_file(backup_filename, buffer, size);
    free(buffer);
    free(random_string);
    free(backup_filename);
    return result;
}

// Restore file
int restore_file(const char *filename, const char *backup_filename) {
    char *buffer = read_file(backup_filename);
    if (buffer == NULL) {
        return -1;
    }
    
    long size = get_file_size(backup_filename);
    int result = write_file(filename, buffer, size);
    free(buffer);
    return result;
}

// Main function
int main() {
    welcome();
    
    char input[100];
    int choice;
    
    while (1) {
        printf("\n[1] Backup file\n[2] Restore file\n[3] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter filename to backup: ");
                scanf("%s", input);
                if (backup_file(input) == 0) {
                    printf("File backed up successfully.\n");
                } else {
                    printf("Error backing up file.\n");
                }
                break;
            case 2:
                printf("Enter filename to restore: ");
                scanf("%s", input);
                printf("Enter backup filename: ");
                scanf("%s", input);
                if (restore_file(input, input) == 0) {
                    printf("File restored successfully.\n");
                } else {
                    printf("Error restoring file.\n");
                }
                break;
            case 3:
                printf("Hasta luego, choomba.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}