//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <string.h>

// You know, just in case someone needs to know how to calculate a punchline.
int calculate_punchline_factor(const char *punchline) {
    int length = strlen(punchline);
    int vowels = 0;

    for (int i = 0; i < length; i++) {
        char ch = punchline[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels++;
        }
    }

    // The funnier the joke, the more vowels, right?
    return length + vowels;
}

// Here's a function to rate the joke by its hilarious factor!
void rate_joke(int factor) {
    if (factor > 40) {
        printf("Joke rating: Stand-up Comedy Superstar!\n");
    } else if (factor > 25) {
        printf("Joke rating: That’s a Chuckle!\n");
    } else if (factor > 10) {
        printf("Joke rating: Mildly Amusing.\n");
    } else {
        printf("Joke rating: Maybe try yoga instead...\n");
    }
}

// A function to get a joke list and calculate the hilarious factors.
void print_joke_array() {
    const char *jokes[] = {
        "Why don’t scientists trust atoms? Because they make up everything!",
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "How does a penguin build its house? Igloos it together!",
        "What do you call fake spaghetti? An impasta!",
        "Why was the math book sad? Because it had too many problems!"
    };

    int joke_count = sizeof(jokes) / sizeof(jokes[0]);
    printf("Welcome to the Awesome Joke Evaluator!\n");

    for (int i = 0; i < joke_count; i++) {
        printf("\nJoke %d: %s\n", i + 1, jokes[i]);
        int factor = calculate_punchline_factor(jokes[i]);
        printf("Hilarious Factor: %d\n", factor);
        rate_joke(factor);
    }

    printf("\nHope you had a good laugh!\n");
}

// The main function where the magic happens!
int main() {
    printf("🔊 Welcome to the Hilarious Factor Calculator! 🔊\n");
    print_joke_array();
    
    printf("\nWould you like to evaluate one more joke? (yes/no): ");
    
    char reply[10];
    scanf("%s", reply);
    
    if (strcmp(reply, "yes") == 0) {
        char custom_joke[255];
        printf("Please tell me your joke: ");
        getchar();  // To consume the newline character left in the input buffer
        fgets(custom_joke, sizeof(custom_joke), stdin);
        
        // Remove newline character from the end, if there is one
        size_t len = strlen(custom_joke);
        if (len > 0 && custom_joke[len - 1] == '\n') {
            custom_joke[len - 1] = '\0';
        }
        
        int factor = calculate_punchline_factor(custom_joke);
        printf("Your joke: %s\n", custom_joke);
        printf("Hilarious Factor: %d\n", factor);
        rate_joke(factor);
    } else {
        printf("Thanks for joining the hilarious journey!\n");
    }

    printf("Remember, laughter is the best medicine! (But don't forget real medicine too.)\n");
    return 0;
}