//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold the summary and the original text
typedef struct {
  char *summary;
  char *original;
} TextSummary;

// A function to create a new TextSummary struct
TextSummary *new_text_summary(char *summary, char *original) {
  TextSummary *text_summary = malloc(sizeof(TextSummary));
  text_summary->summary = strdup(summary);
  text_summary->original = strdup(original);
  return text_summary;
}

// A function to free the memory allocated for a TextSummary struct
void free_text_summary(TextSummary *text_summary) {
  free(text_summary->summary);
  free(text_summary->original);
  free(text_summary);
}

// A function to summarize a text
TextSummary *summarize_text(char *text) {
  // Check if the text is empty
  if (strlen(text) == 0) {
    return new_text_summary("", "");
  }

  // Create a new TextSummary struct
  TextSummary *text_summary = new_text_summary("", text);

  // Summarize the text
  char *summary = malloc(strlen(text) / 2 + 1);
  strcpy(summary, text);
  for (int i = 0; i < strlen(summary); i++) {
    if (i % 2 == 0) {
      summary[i] = toupper(summary[i]);
    } else {
      summary[i] = tolower(summary[i]);
    }
  }
  text_summary->summary = summary;

  // Return the TextSummary struct
  return text_summary;
}

// A function to print a TextSummary struct
void print_text_summary(TextSummary *text_summary) {
  printf("Summary: %s\nOriginal: %s\n", text_summary->summary, text_summary->original);
}

int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text to summarize: ");
  gets(text);

  // Summarize the text
  TextSummary *text_summary = summarize_text(text);

  // Print the summary
  print_text_summary(text_summary);

  // Free the memory allocated for the TextSummary struct
  free_text_summary(text_summary);

  return 0;
}