//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "mystery_box.txt"
#define MAX_ENVELOPE_SIZE 256
#define MAX_ID_SIZE 10
#define MAX_MESSAGE_SIZE 512

typedef struct {
    char id[MAX_ID_SIZE];
    char message[MAX_MESSAGE_SIZE];
} Envelope;

void addEnvelope();
void viewEnvelopes();
void deleteEnvelope();
void clearBuffer();
int envelopeExists(const char *id);
void showSurpriseMessage();

int main() {
    int choice;

    printf("Welcome to the Mystery Box!\n");
    printf("You can add, view, or delete envelopes filled with surprises!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add an Envelope\n");
        printf("2. View Envelopes\n");
        printf("3. Delete an Envelope\n");
        printf("4. Show a Surprise Message\n");
        printf("5. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();
        
        switch (choice) {
            case 1:
                addEnvelope();
                break;
            case 2:
                viewEnvelopes();
                break;
            case 3:
                deleteEnvelope();
                break;
            case 4:
                showSurpriseMessage();
                break;
            case 5:
                printf("Exiting the Mystery Box. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addEnvelope() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Envelope envelope;
    printf("Enter Envelope ID: ");
    fgets(envelope.id, MAX_ID_SIZE, stdin);
    strtok(envelope.id, "\n"); // Remove newline character

    if (envelopeExists(envelope.id)) {
        printf("An envelope with this ID already exists! Please try again.\n");
        fclose(file);
        return;
    }

    printf("Enter your surprise message: ");
    fgets(envelope.message, MAX_MESSAGE_SIZE, stdin);
    fprintf(file, "%s:%s\n", envelope.id, envelope.message);

    fclose(file);
    printf("Envelope added successfully!\n");
}

void viewEnvelopes() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_ENVELOPE_SIZE];
    printf("Current Envelopes:\n");
    while (fgets(line, sizeof(line), file)) {
        char *id = strtok(line, ":");
        char *message = strtok(NULL, "\n");
        printf("ID: %s, Message: %s\n", id, message);
    }

    fclose(file);
}

void deleteEnvelope() {
    char id[MAX_ID_SIZE];
    printf("Enter the ID of the envelope to delete: ");
    fgets(id, MAX_ID_SIZE, stdin);
    strtok(id, "\n"); // Remove newline character

    if (!envelopeExists(id)) {
        printf("No envelope found with this ID!\n");
        return;
    }

    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("tempfile.txt", "w");
    if (!file || !temp) {
        perror("Error opening file");
        return;
    }

    char line[MAX_ENVELOPE_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, id) == NULL) {
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);
    remove(FILENAME);
    rename("tempfile.txt", FILENAME);

    printf("Envelope with ID %s deleted successfully!\n", id);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}

int envelopeExists(const char *id) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        return 0;
    }

    char line[MAX_ENVELOPE_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, id) != NULL) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void showSurpriseMessage() {
    char *surprises[] = {
        "🎉 Surprise! You're amazing!",
        "✨ Hope you have a day full of surprises!",
        "🎈 Keep smiling, the world is your stage!",
        "🌟 You're capable of great things!",
        "💫 Remember to take a moment and enjoy life!"
    };
    int randomIndex = rand() % (sizeof(surprises) / sizeof(surprises[0]));
    printf("%s\n", surprises[randomIndex]);
}