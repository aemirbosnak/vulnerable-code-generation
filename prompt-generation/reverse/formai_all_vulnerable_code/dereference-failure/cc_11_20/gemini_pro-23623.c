//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *token;
    int count;
} Token;

int main() {
    char *resume = "John Doe\n123 Main Street\nAnytown, CA 12345\n(123) 456-7890\njohn.doe@example.com\n\nSummary\n\nA highly motivated and results-oriented individual with 5+ years of experience in software development. Proven ability to work independently and as part of a team, and to deliver high-quality results on time and within budget.\n\nSkills\n\n- Programming Languages: Java, Python, C++, SQL\n- Web Development: HTML, CSS, JavaScript, React\n- Cloud Computing: AWS, Azure, Google Cloud Platform\n- Agile Development: Scrum, Kanban\n\nExperience\n\nSoftware Engineer\nABC Company\nJanuary 2018 - Present\n- Developed and maintained software applications for a variety of clients\n- Worked on a team of developers to deliver high-quality products on time and within budget\n- Mentored junior developers and provided technical support\n\nEducation\n\nBachelor of Science in Computer Science\nUniversity of California, Berkeley\nMay 2017\n\nAwards and Honors\n\n- Dean's List, every semester\n- President of the Computer Science Club\n- Recipient of the Computer Science Department Scholarship";

    // Tokenize the resume
    char *tokens[MAX_TOKENS];
    int num_tokens = 0;
    char *token = strtok(resume, " ");
    while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each token
    Token token_counts[MAX_TOKENS];
    for (int i = 0; i < num_tokens; i++) {
        int found = 0;
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], token_counts[j].token) == 0) {
                token_counts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            token_counts[num_tokens].token = tokens[i];
            token_counts[num_tokens].count = 1;
            num_tokens++;
        }
    }

    // Sort the tokens by count
    for (int i = 0; i < num_tokens; i++) {
        for (int j = i + 1; j < num_tokens; j++) {
            if (token_counts[i].count < token_counts[j].count) {
                Token temp = token_counts[i];
                token_counts[i] = token_counts[j];
                token_counts[j] = temp;
            }
        }
    }

    // Print the top 10 most frequent tokens
    printf("Top 10 most frequent tokens:\n");
    for (int i = 0; i < 10 && i < num_tokens; i++) {
        printf("%s: %d\n", token_counts[i].token, token_counts[i].count);
    }

    return 0;
}