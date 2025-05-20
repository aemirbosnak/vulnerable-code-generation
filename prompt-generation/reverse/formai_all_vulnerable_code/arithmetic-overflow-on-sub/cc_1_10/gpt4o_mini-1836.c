//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 256
#define MAX_USERS 10

typedef struct {
    char username[20];
    int score;
    float time_taken; // seconds
} User;

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a random text to type.\n");
    printf("Try to type it as fast and accurately as possible.\n");
    printf("You will be given a score based on your time taken.\n\n");
}

char* get_random_text() {
    char* texts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "An apple a day keeps the doctor away.",
        "To be or not to be, that is the question.",
        "A journey of a thousand miles begins with a single step.",
        "All that glitters is not gold."
    };
    int random_index = rand() % 5;
    return texts[random_index];
}

void record_user_score(User* users, int* user_count, const char* username, float time_taken) {
    for (int i = 0; i < *user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            // User exists, update score
            users[i].time_taken = time_taken;
            users[i].score = (int)(1000 / time_taken); // score based on time
            return;
        }
    }
    
    // New user, add user
    strcpy(users[*user_count].username, username);
    users[*user_count].time_taken = time_taken;
    users[*user_count].score = (int)(1000 / time_taken); // score based on time
    (*user_count)++;
}

void display_scores(User* users, int user_count) {
    printf("\n--- High Scores ---\n");
    for(int i = 0; i < user_count; i++) {
        printf("User: %s, Score: %d, Time Taken: %.2f seconds\n", users[i].username, users[i].score, users[i].time_taken);
    }
}

void start_typing_test(User* users, int* user_count) {
    char username[20];
    char typed_text[MAX_TEXT_LENGTH];
    char* random_text;

    printf("Enter your username: ");
    scanf("%s", username);

    display_instructions();

    random_text = get_random_text();
    printf("Type the following text:\n%s\n", random_text);

    // Timing the input
    clock_t start_time = clock();

    // Get user input
    printf("> ");
    getchar(); // clear buffer
    fgets(typed_text, MAX_TEXT_LENGTH, stdin);
    typed_text[strcspn(typed_text, "\n")] = 0; // remove newline

    clock_t end_time = clock();
    float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC;

    if(strcmp(typed_text, random_text) == 0) {
        printf("Well done! You typed it correctly in %.2f seconds.\n", time_taken);
    } else {
        printf("Oops! You made a mistake. Try again!\n");
    }

    // Record user score
    record_user_score(users, user_count, username, time_taken);
}

int main() {
    srand(time(NULL));

    User users[MAX_USERS];
    int user_count = 0;
    int play_again;

    do {
        start_typing_test(users, &user_count);
        printf("\nDo you want to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &play_again);
    } while (play_again == 1);

    display_scores(users, user_count);
    return 0;
}