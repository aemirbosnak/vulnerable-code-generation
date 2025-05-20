//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Spam detection rules
typedef struct SpamRule {
    char *pattern;
    int weight;
} SpamRule;

// Spam detection configuration
typedef struct SpamConfig {
    int num_rules;
    SpamRule *rules;
    int threshold;
} SpamConfig;

// Spam flags
#define SPAM_FLAG_NONE 0
#define SPAM_FLAG_LOW 1
#define SPAM_FLAG_MEDIUM 2
#define SPAM_FLAG_HIGH 3

// Load spam detection rules from file
int load_rules(const char *filename, SpamConfig *config) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    int num_rules;
    fscanf(file, "%d", &num_rules);

    config->rules = malloc(sizeof(SpamRule) * num_rules);
    if (config->rules == NULL) {
        fclose(file);
        return -1;
    }

    for (int i = 0; i < num_rules; i++) {
        char pattern[256];
        int weight;
        fscanf(file, "%s %d", pattern, &weight);

        config->rules[i].pattern = strdup(pattern);
        config->rules[i].weight = weight;
    }

    config->num_rules = num_rules;

    fclose(file);

    return 0;
}

// Free spam detection rules
void free_rules(SpamConfig *config) {
    for (int i = 0; i < config->num_rules; i++) {
        free(config->rules[i].pattern);
    }

    free(config->rules);
}

// Check if a string matches a spam pattern
int match_pattern(const char *string, const char *pattern) {
    int string_len = strlen(string);
    int pattern_len = strlen(pattern);

    for (int i = 0; i < string_len - pattern_len + 1; i++) {
        if (strncmp(string + i, pattern, pattern_len) == 0) {
            return 1;
        }
    }

    return 0;
}

// Calculate spam score for a string
int spam_score(const char *string, const SpamConfig *config) {
    int score = 0;

    for (int i = 0; i < config->num_rules; i++) {
        if (match_pattern(string, config->rules[i].pattern)) {
            score += config->rules[i].weight;
        }
    }

    return score;
}

// Classify a string as spam or not spam
int classify_spam(const char *string, const SpamConfig *config) {
    int score = spam_score(string, config);

    if (score < config->threshold) {
        return SPAM_FLAG_NONE;
    } else if (score < 2 * config->threshold) {
        return SPAM_FLAG_LOW;
    } else if (score < 3 * config->threshold) {
        return SPAM_FLAG_MEDIUM;
    } else {
        return SPAM_FLAG_HIGH;
    }
}

// Example usage
int main() {
    // Load spam detection rules
    SpamConfig config;
    if (load_rules("spam_rules.txt", &config) != 0) {
        fprintf(stderr, "Error: Could not load spam rules\n");
        return EXIT_FAILURE;
    }

    // Set spam detection threshold
    config.threshold = 10;

    // Check if a string is spam
    char *string = "This is a spam email. Click here to win a free prize!";
    int flag = classify_spam(string, &config);

    // Print spam classification
    switch (flag) {
    case SPAM_FLAG_NONE:
        printf("Not spam\n");
        break;
    case SPAM_FLAG_LOW:
        printf("Low spam risk\n");
        break;
    case SPAM_FLAG_MEDIUM:
        printf("Medium spam risk\n");
        break;
    case SPAM_FLAG_HIGH:
        printf("High spam risk\n");
        break;
    }

    // Free spam detection rules
    free_rules(&config);

    return EXIT_SUCCESS;
}