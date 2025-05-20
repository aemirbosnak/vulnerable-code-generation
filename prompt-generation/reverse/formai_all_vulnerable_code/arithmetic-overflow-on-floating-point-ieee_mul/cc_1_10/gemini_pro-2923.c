//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Array of words for the test
char *words[MAX_WORDS] = {
  "hello", "world", "computer", "programming", "language",
  "software", "engineer", "developer", "technology", "internet",
  "database", "network", "system", "application", "user",
  "interface", "design", "algorithm", "data", "structure",
  "artificial", "intelligence", "machine", "learning", "cloud",
  "computing", "big", "data", "analytics", "virtual",
  "reality", "augmented", "reality", "mixed", "reality",
  "blockchain", "cryptocurrency", "bitcoin", "ethereum", "smart",
  "contract", "decentralized", "autonomous", "vehicle", "iot",
  "robotics", "automation", "cybersecurity", "quantum", "computing",
  "metaverse", "web", "3.0", "social", "media",
  "digital", "marketing", "content", "creator", "influencer",
  "e-commerce", "marketplace", "saas", "paas", "iaas",
  "devops", "agile", "scrum", "kanban", "waterfall",
  "project", "management", "team", "collaboration", "communication",
  "leadership", "innovation", "creativity", "problem", "solving",
  "critical", "thinking", "analytical", "skills", "communication",
  "skills", "interpersonal", "skills", "time", "management",
  "stress", "management", "conflict", "resolution", "negotiation",
  "skills", "ethics", "values", "integrity", "professionalism",
  "work", "life", "balance", "wellbeing", "mindfulness",
  "gratitude", "happiness", "success", "fulfillment", "meaning",
  "purpose", "passion", "drive", "ambition", "determination",
  "resilience", "perseverance", "grit", "tenacity", "never",
  "give", "up", "attitude", "belief", "mindset",
  "growth", "mindset", "learning", "mindset", "abundance",
  "mindset", "scarcity", "mindset", "fixed", "mindset", "growth",
  "mindset", "positive", "mindset", "negative", "mindset",
  "rational", "mindset", "emotional", "mindset", "logical",
  "mindset", "intuitive", "mindset", "analytical", "mindset",
  "creative", "mindset", "practical", "mindset", "realistic",
  "mindset", "idealistic", "mindset", "optimistic", "mindset",
  "pessimistic", "mindset", "introverted", "mindset", "extroverted",
  "mindset", "thinker", "mindset", "feeler", "mindset", "judger",
  "mindset", "perceiver", "mindset", "assertive", "mindset",
  "avoidant", "mindset", "aggressive", "mindset", "passive",
  "mindset", "dependent", "mindset", "independent", "mindset",
  "conformist", "mindset", "rebellious", "mindset", "traditionalist",
  "mindset", "modernist", "mindset", "conservative", "mindset",
  "liberal", "mindset", "dogmatic", "mindset", "open",
  "minded", "mindset", "closed", "minded", "mindset", "shallow",
  "mindset", "deep", "mindset", "superficial", "mindset",
  "profound", "mindset", "narrow", "minded", "mindset", "broad",
  "minded", "mindset", "shallow", "minded", "mindset", "deep",
  "minded", "mindset", "superficial", "mindset", "profound",
  "mindset", "narrow", "minded", "mindset", "broad",
  "minded", "mindset", "shallow", "minded", "mindset", "deep",
  "minded", "mindset", "superficial", "mindset", "profound",
  "mindset", "narrow", "minded", "mindset", "broad",
  "minded", "mindset", "shallow", "minded", "mindset", "deep",
  "minded", "mindset", "superficial", "mindset", "profound",
  "mindset", "narrow", "minded", "mindset", "broad",
  "minded", "mindset", "shallow", "minded", "mindset", "deep",
  "minded", "mindset", "superficial", "mindset", "profound",
  "mindset", "narrow", "minded", "mindset", "broad",
  "minded", "mindset", "shallow", "minded", "mindset", "deep",
  "minded", "mindset", "superficial", "mindset", "profound",
  "mindset", "narrow", "minded", "mindset", "broad",
  "minded", "mindset", "shallow", "minded", "mindset", "deep",
  "minded", "mindset", "superficial", "mindset", "profound",
  "mindset", "narrow", "minded", "mindset", "broad"
};

// Function to generate a random number between 0 and max
int random_number(int max) {
  return rand() % max;
}

// Function to generate a random word from the array of words
char *random_word() {
  return words[random_number(MAX_WORDS)];
}

// Function to get the length of a string
int string_length(char *string) {
  int length = 0;
  while (*string != '\0') {
    length++;
    string++;
  }
  return length;
}

// Function to compare two strings
int string_compare(char *string1, char *string2) {
  while (*string1 != '\0' && *string2 != '\0') {
    if (*string1 != *string2) {
      return *string1 - *string2;
    }
    string1++;
    string2++;
  }
  return *string1 - *string2;
}

// Function to print the results of the test
void print_results(int correct, int incorrect, int total, float accuracy) {
  printf("Correct: %d\n", correct);
  printf("Incorrect: %d\n", incorrect);
  printf("Total: %d\n", total);
  printf("Accuracy: %.2f%%\n", accuracy * 100);
}

// Function to run the typing speed test
void typing_speed_test() {
  // Get the start time
  time_t start_time = time(NULL);

  // Generate a random word
  char *word = random_word();

  // Get the length of the word
  int word_length = string_length(word);

  // Create a buffer to store the user's input
  char buffer[MAX_WORD_LENGTH + 1];

  // Get the user's input
  printf("Type the word: %s\n", word);
  scanf("%s", buffer);

  // Get the end time
  time_t end_time = time(NULL);

  // Calculate the time taken to type the word
  float time_taken = difftime(end_time, start_time);

  // Calculate the accuracy
  float accuracy = (float)word_length / (time_taken * 60);

  // Print the results
  print_results(1, 0, 1, accuracy);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Run the typing speed test
  typing_speed_test();

  return 0;
}