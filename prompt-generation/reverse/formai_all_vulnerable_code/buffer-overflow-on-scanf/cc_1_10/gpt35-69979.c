//FormAI DATASET v1.0 Category: Browser Plugin ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char url[50];
    char title[25];
} Webpage;

Webpage history[10];
int current_index = -1;

void add_page(char url[], char title[]) {
    current_index++;
    if (current_index == 10) { // if the history array is full, overwrite the oldest entry
        memmove(history, &history[1], sizeof(history) * 9);
        current_index--;
    }
    strcpy(history[current_index].url, url);
    strcpy(history[current_index].title, title);
}

void print_history() {
    printf("Browsing history:\n");
    for (int i = 0; i <= current_index; i++) {
        printf("%d. %s: %s\n", i+1, history[i].url, history[i].title);
    }
}

bool is_youtube(char url[]) {
    char* youtube = "www.youtube.com";
    if (strstr(url, youtube) != NULL) {
        return true;
    }
    return false;
}

void youtube_plugin(char url[]) {
    printf("--------------------------------------------------\n");
    printf("Welcome to the YouTube Plugin!\n");
    printf("URL: %s\n\n", url);

    printf("What would you like to do?\n");
    printf("1. Search for videos\n");
    printf("2. View your subscriptions\n");
    printf("3. Watch a specific video\n");
    printf("4. Exit plugin\n");

    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter your search query: ");
            char search[50];
            scanf("%s", search);
            printf("Here are the search results for %s:\n", search);
            // code to search YouTube for videos matching query
            break;
        case 2:
            printf("Here are your subscriptions:\n");
            // code to retrieve user's YouTube subscriptions
            break;
        case 3:
            printf("Enter the ID of the video you want to watch (e.g. dQw4w9WgXcQ): ");
            char video_id[15];
            scanf("%s", video_id);
            printf("Now watching video %s...\n", video_id);
            // code to play selected video
            break;
        case 4:
            printf("Exiting YouTube Plugin...\n");
            break;
        default:
            printf("Invalid choice. Exiting YouTube Plugin...\n");
            break;
    }
    printf("--------------------------------------------------\n");
}

void new_page(char url[], char title[]) {
    printf("Loading page...\n");
    printf("Title: %s\n", title);
    printf("URL: %s\n", url);

    if (is_youtube(url)) {
        youtube_plugin(url);
    }

    add_page(url, title);
}

int main() {
    new_page("www.google.com", "Google");
    print_history();

    new_page("www.youtube.com", "YouTube");
    print_history();

    new_page("www.twitter.com", "Twitter");
    print_history();

    new_page("www.reddit.com", "Reddit");
    print_history();

    new_page("www.facebook.com", "Facebook");
    print_history();

    return 0;
}