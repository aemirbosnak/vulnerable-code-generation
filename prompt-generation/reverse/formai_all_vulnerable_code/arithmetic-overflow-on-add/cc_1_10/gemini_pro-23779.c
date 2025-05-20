//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 1024
#define MAX_MESSAGE_SIZE 1024

struct spam_key {
  char key[MAX_KEY_SIZE];
  time_t expiration_date;
};

typedef struct spam_key SpamKey;

struct spam_detection_result {
  int is_spam;
  SpamKey key;
};

typedef struct spam_detection_result SpamDetectionResult;

int is_spam(char *message) {
  int i, j;
  char *keywords[] = {"free", "money", "win", "click here", "offer"};
  int num_keywords = sizeof(keywords) / sizeof(char *);

  for (i = 0; i < num_keywords; i++) {
    for (j = 0; j < strlen(message); j++) {
      if (strstr(&message[j], keywords[i]) != NULL) {
        return 1;
      }
    }
  }

  return 0;
}

SpamDetectionResult detect_spam(char *message, SpamKey key) {
  SpamDetectionResult result;
  result.is_spam = is_spam(message);
  result.key = key;

  return result;
}

int main(void) {
  char message[] = "This is a spam message. Click here to win a free prize!";
  SpamKey key;
  SpamDetectionResult result;

  key.expiration_date = time(NULL) + 3600;
  strcpy(key.key, "abcdefghij");

  result = detect_spam(message, key);

  if (result.is_spam) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  if (result.key.expiration_date < time(NULL)) {
    printf("The key has expired.\n");
  }

  return 0;
}