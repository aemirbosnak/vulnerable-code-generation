//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATAS 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

typedef struct {
    Metadata metadata[MAX_METADATAS];
    int count;
} MetadataExtractor;

void initializeExtractor(MetadataExtractor *extractor) {
    extractor->count = 0;
}

void addMetadata(MetadataExtractor *extractor, const char *key, const char *value) {
    if (extractor->count < MAX_METADATAS) {
        strncpy(extractor->metadata[extractor->count].key, key, MAX_KEY_LENGTH);
        strncpy(extractor->metadata[extractor->count].value, value, MAX_VALUE_LENGTH);
        extractor->count++;
    } else {
        printf("Metadata limit reached. Cannot add more.\n");
    }
}

void displayMetadata(const MetadataExtractor *extractor) {
    printf("Metadata List:\n");
    for (int i = 0; i < extractor->count; i++) {
        printf("%s: %s\n", extractor->metadata[i].key, extractor->metadata[i].value);
    }
}

void searchMetadata(const MetadataExtractor *extractor, const char *key) {
    for (int i = 0; i < extractor->count; i++) {
        if (strcmp(extractor->metadata[i].key, key) == 0) {
            printf("Found Metadata: %s = %s\n", key, extractor->metadata[i].value);
            return;
        }
    }
    printf("Metadata with key '%s' not found.\n", key);
}

void deleteMetadata(MetadataExtractor *extractor, const char *key) {
    for (int i = 0; i < extractor->count; i++) {
        if (strcmp(extractor->metadata[i].key, key) == 0) {
            for (int j = i; j < extractor->count - 1; j++) {
                extractor->metadata[j] = extractor->metadata[j + 1];
            }
            extractor->count--;
            printf("Metadata with key '%s' deleted.\n", key);
            return;
        }
    }
    printf("Metadata with key '%s' not found for deletion.\n", key);
}

int main() {
    MetadataExtractor extractor;
    initializeExtractor(&extractor);

    int choice;
    char key[MAX_KEY_LENGTH], value[MAX_VALUE_LENGTH];

    do {
        printf("\n--- Metadata Extractor ---\n");
        printf("1. Add Metadata\n");
        printf("2. Display Metadata\n");
        printf("3. Search Metadata\n");
        printf("4. Delete Metadata\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';  // Remove trailing newline
                printf("Enter value: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = '\0'; // Remove trailing newline
                addMetadata(&extractor, key, value);
                break;

            case 2:
                displayMetadata(&extractor);
                break;

            case 3:
                printf("Enter key to search: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';  // Remove trailing newline
                searchMetadata(&extractor, key);
                break;

            case 4:
                printf("Enter key to delete: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';  // Remove trailing newline
                deleteMetadata(&extractor, key);
                break;

            case 5:
                printf("Exiting the Metadata Extractor. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}