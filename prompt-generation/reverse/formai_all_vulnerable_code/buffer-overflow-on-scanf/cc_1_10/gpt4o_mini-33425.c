//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCROLLS 10
#define SCROLL_LENGTH 256

typedef struct {
    char sender[50];
    char receiver[50];
    char content[SCROLL_LENGTH];
} Scroll;

typedef struct {
    Scroll scrolls[MAX_SCROLLS];
    int count;
} ScrollPost;

void send_scroll(ScrollPost *post, const char *sender, const char *receiver, const char *content);
void receive_scrolls(ScrollPost *post);
void display_scroll(const Scroll *scroll);
void clear_scrolls(ScrollPost *post);

int main() {
    ScrollPost scrollPost;
    scrollPost.count = 0;
    int choice;

    while (1) {
        printf("\n=== The Grand Scroll Dispatcher ===\n");
        printf("1. Send a Scroll\n");
        printf("2. Receive Scrolls\n");
        printf("3. Clean the Scrolls\n");
        printf("4. Depart the Program\n");
        printf("===================================\n");
        printf("Choose thy action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char sender[50], receiver[50], content[SCROLL_LENGTH];
                printf("Enter the sender's name: ");
                scanf("%s", sender);
                printf("Enter the receiver's name: ");
                scanf("%s", receiver);
                printf("Compose your scroll: ");
                getchar(); // Clear newline
                fgets(content, SCROLL_LENGTH, stdin);
                content[strcspn(content, "\n")] = 0; // Remove newline

                send_scroll(&scrollPost, sender, receiver, content);
                break;
            }
            case 2:
                receive_scrolls(&scrollPost);
                break;
            case 3:
                clear_scrolls(&scrollPost);
                break;
            case 4:
                printf("Farewell! Until we meet again!\n");
                exit(0);
            default:
                printf("Mysterious choice! Please select again.\n");
        }
    }
    return 0;
}

void send_scroll(ScrollPost *post, const char *sender, const char *receiver, const char *content) {
    if (post->count < MAX_SCROLLS) {
        Scroll newScroll;
        strcpy(newScroll.sender, sender);
        strcpy(newScroll.receiver, receiver);
        strcpy(newScroll.content, content);

        post->scrolls[post->count] = newScroll;
        post->count++;

        printf("The scroll hath been sent forth!\n");
    } else {
        printf("Alas! The scrolls are full! Thou must clear some before sending more.\n");
    }
}

void receive_scrolls(ScrollPost *post) {
    if (post->count == 0) {
        printf("There are no scrolls to receive! The winds are silent.\n");
        return;
    }

    printf("\n=== Retrieved Scrolls ===\n");
    for (int i = 0; i < post->count; i++) {
        display_scroll(&post->scrolls[i]);
    }
}

void display_scroll(const Scroll *scroll) {
    printf("From: %s\n", scroll->sender);
    printf("To: %s\n", scroll->receiver);
    printf("Content: %s\n", scroll->content);
    printf("--------------------------\n");
}

void clear_scrolls(ScrollPost *post) {
    post->count = 0;
    printf("All scrolls have been vaporized into thin air!\n");
}