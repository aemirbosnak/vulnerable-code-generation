//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KNIGHTS 100
#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 256

typedef struct Knight {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Knight;

Knight knights[MAX_KNIGHTS];
int knight_count = 0;

void add_knight() {
    if (knight_count >= MAX_KNIGHTS) {
        printf("Alas! The court is full with knights. No more can join!\n");
        return;
    }
    printf("Enter the name of the brave knight: ");
    scanf("%s", knights[knight_count].name);
    printf("What message dost thou wish to convey? ");
    scanf(" %[^\n]", knights[knight_count].message); 
    knight_count++;
    printf("The noble knight %s hath been added to the list!\n", knights[knight_count - 1].name);
}

void send_message() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the knight to send a message to: ");
    scanf("%s", name);
    
    for (int i = 0; i < knight_count; i++) {
        if (strcmp(knights[i].name, name) == 0) {
            printf("To noble %s, thy message is: %s\n", knights[i].name, knights[i].message);
            return;
        }
    }
    printf("Alas! No knight named %s could be found in the court.\n", name);
}

void display_knights() {
    if (knight_count == 0) {
        printf("The list of knights is empty. No gallant souls to be found!\n");
        return;
    }
    printf("List of Knights in the court:\n");
    for (int i = 0; i < knight_count; i++) {
        printf("Knight %d: %s - Message: %s\n", i + 1, knights[i].name, knights[i].message);
    }
}

void remove_knight() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the knight to be removed from the court: ");
    scanf("%s", name);

    for (int i = 0; i < knight_count; i++) {
        if (strcmp(knights[i].name, name) == 0) {
            for (int j = i; j < knight_count - 1; j++) {
                knights[j] = knights[j + 1];
            }
            knight_count--;
            printf("The valiant knight %s has been removed from the court!\n", name);
            return;
        }
    }
    printf("Alas! No knight by the name of %s dost dwell here!\n", name);
}

void display_menu() {
    printf("\n--- The Knight's Mailing List Manager ---\n");
    printf("1. Add a Knight\n");
    printf("2. Send a Message\n");
    printf("3. Display Knights\n");
    printf("4. Remove a Knight\n");
    printf("5. Leave the Court\n");
}

int main() {
    int choice;
    
    do {
        display_menu();
        printf("Choose thy action: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_knight();
                break;
            case 2:
                send_message();
                break;
            case 3:
                display_knights();
                break;
            case 4:
                remove_knight();
                break;
            case 5:
                printf("Thou hast chosen to leave the court. Farewell!\n");
                break;
            default:
                printf("Nay, that is not a noble choice! Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}