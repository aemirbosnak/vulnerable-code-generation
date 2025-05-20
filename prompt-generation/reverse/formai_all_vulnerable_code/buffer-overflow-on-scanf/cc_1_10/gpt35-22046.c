//FormAI DATASET v1.0 Category: Digital Diary ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct diary {
    char date[50];
    char entry[500];
};

void newEntry(struct diary *entries, int *numEntries) {
    printf("Enter today's date (DD/MM/YYYY): ");
    scanf("%s", entries[*numEntries].date);
    printf("Enter your entry for today (max 500 characters):\n");
    scanf(" %[^\n]%*c", entries[*numEntries].entry);
    printf("Entry successfully added!\n");
    (*numEntries)++;
}

void viewEntries(struct diary *entries, int *numEntries) {
    if (*numEntries == 0) {
        printf("\nNo entries to display.\n");
        return;
    }
    printf("\n-------------------------\n");
    for (int i = 0; i < *numEntries; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Entry: %s\n", entries[i].entry);
        printf("-------------------------\n");
    }
}

void generateRandomEntry(struct diary *entries, int *numEntries) {
    char *randomEntries[] = {
        "Today was a lovely day. I spent most of it reading my favorite book in the park.",
        "I woke up feeling very anxious today. I'm not really sure why.",
        "I went for a long run this morning. It really helped me clear my mind.",
        "It's my friend's birthday today! I'm so excited to celebrate with her later.",
        "I had a really interesting conversation with a stranger on the bus today.",
        "I'm feeling pretty overwhelmed with work right now. Trying to stay positive though.",
        "I made a delicious dinner tonight. Cooking always helps me relax.",
        "I watched a really inspiring TED talk today. It gave me a lot to think about.",
        "I took a day off today and spent it exploring the city. It was so much fun!",
        "I'm feeling pretty lonely lately. I should try to reach out to some friends for support."
    };
    srand(time(NULL));
    int index = rand() % 10;
    printf("\nAutomatically generated entry:\n");
    printf("Date: %s\n", entries[*numEntries].date);
    printf("Entry: %s\n", randomEntries[index]);
    printf("-------------------------\n");
    strcpy(entries[*numEntries].entry, randomEntries[index]);
    (*numEntries)++;
}

int main() {
    int numEntries = 0;
    struct diary entries[100];
    int choice;
    do {
        printf("\n------Digital Diary------\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Generate random entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: newEntry(entries, &numEntries); break;
            case 2: viewEntries(entries, &numEntries); break;
            case 3: generateRandomEntry(entries, &numEntries); break;
            case 4: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}