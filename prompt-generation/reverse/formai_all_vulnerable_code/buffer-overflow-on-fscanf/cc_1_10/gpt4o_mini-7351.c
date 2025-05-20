//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_ENTRIES 1000
#define BUFFER_SIZE 256

typedef struct {
    int userID;
    char name[BUFFER_SIZE];
    int age;
    int purchases;
} User;

typedef struct {
    int userID;
    float amountSpent;
} Purchase;

User users[MAX_USERS];
Purchase purchases[MAX_ENTRIES];
int userCount = 0;
int purchaseCount = 0;

// Function prototypes
void loadData(const char *userFile, const char *purchaseFile);
void addUser(int userID, const char *name, int age, int purchases);
void addPurchase(int userID, float amount);
void analyzeData();
void printReport(User user);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <user_data_file> <purchase_data_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadData(argv[1], argv[2]);
    analyzeData();

    return EXIT_SUCCESS;
}

void loadData(const char *userFile, const char *purchaseFile) {
    FILE *usersFile = fopen(userFile, "r");
    FILE *purchasesFile = fopen(purchaseFile, "r");

    if (usersFile == NULL || purchasesFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(usersFile, "%d %s %d %d", 
                  &users[userCount].userID, 
                  users[userCount].name, 
                  &users[userCount].age, 
                  &users[userCount].purchases) != EOF) {
        userCount++;
        if (userCount >= MAX_USERS) {
            break;
        }
    }

    while (fscanf(purchasesFile, "%d %f", 
                  &purchases[purchaseCount].userID, 
                  &purchases[purchaseCount].amountSpent) != EOF) {
        purchaseCount++;
        if (purchaseCount >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(usersFile);
    fclose(purchasesFile);
}

void addUser(int userID, const char *name, int age, int purchases) {
    if (userCount < MAX_USERS) {
        users[userCount].userID = userID;
        strncpy(users[userCount].name, name, BUFFER_SIZE);
        users[userCount].age = age;
        users[userCount].purchases = purchases;
        userCount++;
    } else {
        printf("User limit reached!\n");
    }
}

void addPurchase(int userID, float amount) {
    if (purchaseCount < MAX_ENTRIES) {
        purchases[purchaseCount].userID = userID;
        purchases[purchaseCount].amountSpent = amount;
        purchaseCount++;
    } else {
        printf("Purchase limit reached!\n");
    }
}

void analyzeData() {
    printf("\n--- Data Analysis Report ---\n");
    for (int i = 0; i < userCount; i++) {
        User user = users[i];
        float totalSpent = 0.0;
        int purchaseCountForUser = 0;

        for (int j = 0; j < purchaseCount; j++) {
            if (purchases[j].userID == user.userID) {
                totalSpent += purchases[j].amountSpent;
                purchaseCountForUser++;
            }
        }

        printReport(user);
        printf("Total Amount Spent: %.2f\n", totalSpent);
        printf("Total Purchases Made: %d\n\n", purchaseCountForUser);
    }
}

void printReport(User user) {
    printf("User ID: %d\n", user.userID);
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Number of Purchases Recorded: %d\n", user.purchases);
}