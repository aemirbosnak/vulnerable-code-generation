//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enchant_text(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] + key;  // Simple caesar cipher
    }
}

void disenchant_text(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] - key;  // Reversing the caesar cipher
    }
}

void read_scroll(const char *filename, char **content) {
    FILE *scroll = fopen(filename, "r");
    if (!scroll) {
        perror("Could not open the scroll");
        exit(EXIT_FAILURE);
    }
    
    fseek(scroll, 0, SEEK_END);
    long length = ftell(scroll);
    fseek(scroll, 0, SEEK_SET);

    *content = malloc(length + 1);
    fread(*content, 1, length, scroll);
    (*content)[length] = '\0';
    fclose(scroll);
}

void write_scroll(const char *filename, const char *content) {
    FILE *scroll = fopen(filename, "w");
    if (!scroll) {
        perror("Could not create the new scroll");
        exit(EXIT_FAILURE);
    }
    
    fprintf(scroll, "%s", content);
    fclose(scroll);
}

int main() {
    int key;
    char *original_content = NULL;
    char *enchanted_content;

    printf("Hark, noble keeper of the words! Enter the mystical key for encryption: ");
    scanf("%d", &key);
    
    // Clear the input buffer
    while (getchar() != '\n');

    printf("Pray, provide the name of the scroll to be enchanted (the file to encrypt): ");
    char filename[256];
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline character

    read_scroll(filename, &original_content);
    
    enchanted_content = malloc(strlen(original_content) + 1);
    strcpy(enchanted_content, original_content);
    
    enchant_text(enchanted_content, key);
    
    char enchanted_filename[256];
    snprintf(enchanted_filename, sizeof(enchanted_filename), "enchanted_%s", filename);
    write_scroll(enchanted_filename, enchanted_content);

    printf("The scroll hath been enchanted and saved as: %s\n", enchanted_filename);
    
    // Decrypt (disenchant) the contents     
    printf("Wouldst thou like to disenchate? (y/n): ");
    char response;
    scanf(" %c", &response);
    
    if (response == 'y' || response == 'Y') {
        disenchant_text(enchanted_content, key);
        
        char disenchant_filename[256];
        snprintf(disenchant_filename, sizeof(disenchant_filename), "disenchanted_%s", filename);
        write_scroll(disenchant_filename, enchanted_content);
        
        printf("The scroll hath been disenchanted and saved as: %s\n", disenchant_filename);
    }
    
    // Free allocated memory
    free(original_content);
    free(enchanted_content);

    return 0;
}