//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <string.h>

// Define a custom data type for spam filter rules
typedef struct SpamRule {
    char *pattern;
    int priority;
} SpamRule;

// Function to check if a string matches a given spam filter rule
int check_rule(const char *str, const SpamRule *rule) {
    return strstr(str, rule->pattern) != NULL;
}

// Function to classify a string as spam or legitimate based on a set of spam filter rules
int classify_spam(const char *str, const SpamRule *rules, int num_rules) {
    int score = 0;

    // Iterate through the spam filter rules and check if the string matches any of them
    for (int i = 0; i < num_rules; i++) {
        if (check_rule(str, &rules[i])) {
            score += rules[i].priority;
        }
    }

    // Return 1 if the spam score exceeds a threshold, otherwise return 0
    return score > 10;
}

// Main function
int main() {
    // Define a set of spam filter rules
    SpamRule rules[] = {
        {"free", 1},
        {"$$$", 5},
        {"viagra", 10},
        {"click here", 3},
        {"you have won", 7},
    };

    const int num_rules = sizeof(rules) / sizeof(rules[0]);

    // Get the input string from the user
    char str[1024];
    printf("Enter a string to check for spam: ");
    gets(str);

    // Classify the string as spam or legitimate
    int is_spam = classify_spam(str, rules, num_rules);

    // Print the result
    if (is_spam) {
        printf("The string is classified as spam.\n");
    } else {
        printf("The string is classified as legitimate.\n");
    }

    return 0;
}