//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 10000
#define MAX_EMAIL_LEN 2001
#define SPAM_THRESHOLD 0.5

/*
 Initialization struct for each email
 */
typedef struct {
    int spam;
    char text[MAX_EMAIL_LEN];
} Email;

/*
 Function prototypes
 */
void read_emails(char *filename, Email *emails, int *num_emails);
int is_spam(char *text);
double calculate_spam_probability(char *text);
int count_occurrences(char *word, char *text);
char *to_lowercase(char *string);
double get_total_words(char *text);
void print_summary(Email *emails, int num_emails);

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("usage: %s emails.txt\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    Email *emails = (Email *) malloc(MAX_EMAILS * sizeof(Email));
    if(emails == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }
    
    int num_emails;
    read_emails(filename, emails, &num_emails);

    for(int i = 0; i < num_emails; i++) {
        double probability = calculate_spam_probability(emails[i].text);
        if(probability >= SPAM_THRESHOLD) {
            emails[i].spam = 1;
        }
    }

    print_summary(emails, num_emails);

    free(emails);

    return 0;
}

/*
 Read in emails from a file and store them in an array
 */
void read_emails(char *filename, Email *emails, int *num_emails) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    char line[MAX_EMAIL_LEN];
    int email_index = 0;
    while(fgets(line, MAX_EMAIL_LEN, fp)) {
        int len = strlen(line);
        if(line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        strcpy(emails[email_index].text, line);
        emails[email_index].spam = 0;
        email_index++;
        if(email_index == MAX_EMAILS) {
            break;
        }
    }

    *num_emails = email_index;

    fclose(fp);
}

/*
 Determine if a piece of text is spam by checking for certain keywords
 */
int is_spam(char *text) {
    int num_keywords = 5;
    char *keywords[] = {"viagra", "cialis", "enlarge", "lottery", "inheritance"};
    for(int i = 0; i < num_keywords; i++) {
        if(strstr(text, keywords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

/*
 Calculate the probability that a given piece of text is spam
 */
double calculate_spam_probability(char *text) {
    double spam_probability = 0.0;
    char *lowercase_text = to_lowercase(text);
    int num_keywords = 5;
    char *keywords[] = {"viagra", "cialis", "enlarge", "lottery", "inheritance"};
    for(int i = 0; i < num_keywords; i++) {
        int count = count_occurrences(keywords[i], lowercase_text);
        double probability = (double) count / (double) get_total_words(lowercase_text);
        spam_probability += probability;
    }
    free(lowercase_text);
    return spam_probability;
}

/*
 Count the number of times a given word appears in a piece of text
 */
int count_occurrences(char *word, char *text) {
    char *ptr = text;
    int count = 0;
    while((ptr = strstr(ptr, word))) {
        count++;
        ptr++;
    }
    return count;
}

/*
 Convert a string to lowercase
 */
char *to_lowercase(char *string) {
    char *lowercase = (char *) malloc((strlen(string) + 1) * sizeof(char));
    if(lowercase == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }
    for(int i = 0; i < strlen(string); i++) {
        lowercase[i] = tolower(string[i]);
    }
    lowercase[strlen(string)] = '\0';
    return lowercase;
}

/*
 Get the total number of words in a piece of text
 */
double get_total_words(char *text) {
    double count = 0.0;
    char *token = strtok(text, " ,.;:!?()\n");
    while(token != NULL) {
        count++;
        token = strtok(NULL, " ,.;:!?()\n");
    }
    return count;
}

/*
 Print out a summary of the emails and whether they are spam or not
 */
void print_summary(Email *emails, int num_emails) {
    int num_spam = 0;
    int num_non_spam = 0;
    for(int i = 0; i < num_emails; i++) {
        if(emails[i].spam) {
            printf("Spam: %s\n", emails[i].text);
            num_spam++;
        }
        else {
            printf("Not Spam: %s\n", emails[i].text);
            num_non_spam++;
        }
    }
    printf("Total emails: %d\n", num_emails);
    printf("Spam: %d\n", num_spam);
    printf("Not Spam: %d\n", num_non_spam);
    printf("Spam Probability Threshold: %f\n", SPAM_THRESHOLD);
}