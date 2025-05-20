//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

Subscriber mailingList[MAX_SUBSCRIBERS];
int subscriberCount = 0;

void displayMenu() {
    printf("\n<< Mailing List Manager >>\n");
    printf("1. Add subscriber\n");
    printf("2. Remove subscriber\n");
    printf("3. Display subscribers\n");
    printf("4. Save to file\n");
    printf("5. Load from file\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

void addSubscriber() {
    if (subscriberCount >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }
    
    Subscriber newSubscriber;
    
    printf("Enter name: ");
    scanf(" %[^\n]%*c", newSubscriber.name);
    printf("Enter email: ");
    scanf(" %[^\n]%*c", newSubscriber.email);
    
    mailingList[subscriberCount] = newSubscriber;
    subscriberCount++;
    
    printf("Subscriber added successfully!\n");
}

void removeSubscriber() {
    char email[MAX_EMAIL_LEN];
    
    printf("Enter the email of the subscriber to remove: ");
    scanf(" %[^\n]%*c", email);
    
    for (int i = 0; i < subscriberCount; i++) {
        if (strcmp(mailingList[i].email, email) == 0) {
            for (int j = i; j < subscriberCount - 1; j++) {
                mailingList[j] = mailingList[j + 1];
            }
            subscriberCount--;
            printf("Subscriber removed successfully!\n");
            return;
        }
    }
    printf("Subscriber not found.\n");
}

void displaySubscribers() {
    if (subscriberCount == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }
    printf("\nList of Subscribers:\n");
    for (int i = 0; i < subscriberCount; i++) {
        printf("Name: %s, Email: %s\n", mailingList[i].name, mailingList[i].email);
    }
}

void saveToFile() {
    FILE *file = fopen("subscribers.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < subscriberCount; i++) {
        fprintf(file, "%s,%s\n", mailingList[i].name, mailingList[i].email);
    }
    
    fclose(file);
    printf("Subscribers saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("subscribers.txt", "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    subscriberCount = 0; // Reset subscriber count for loading
    while (fscanf(file, " %49[^,],%99[^\n]", mailingList[subscriberCount].name, mailingList[subscriberCount].email) == 2) {
        subscriberCount++;
        if (subscriberCount >= MAX_SUBSCRIBERS) {
            printf("Reached maximum subscribers limit while loading.\n");
            break;
        }
    }
    
    fclose(file);
    printf("Subscribers loaded from file successfully!\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                displaySubscribers();
                break;
            case 4:
                saveToFile();
                break;
            case 5:
                loadFromFile();
                break;
            case 6:
                printf("Exiting the mailing list manager.\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}