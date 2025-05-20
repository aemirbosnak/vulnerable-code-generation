//FormAI DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
  char name[50] = "Happy";
  char message[100] = "Hello, ";

  printf("What's your name?\n");
  scanf("%s", name);

  strcat(message, name);
  strcat(message, "!");

  printf("%s\n", message);

  int len = strlen(message);
  printf("The length of the message is %d\n", len);

  char vowels[] = {'a', 'e', 'i', 'o', 'u'};
  int num_vowels = sizeof(vowels) / sizeof(vowels[0]);
  int vowel_count = 0;

  for (int i = 0; i < len; i++) {
    for (int j = 0; j < num_vowels; j++) {
      if (message[i] == vowels[j]) {
        vowel_count++;
      }
    }
  }

  printf("The message contains %d vowels\n", vowel_count);

  char reverse_message[100];
  int index = strlen(message) - 1;

  for (int i = 0; i < len; i++) {
    reverse_message[i] = message[index];
    index--;
  }

  printf("The reversed message is: %s\n", reverse_message);

  char padded_message[100];

  for (int i = 0; i < (len + 10); i++) {
    padded_message[i] = '-';
  }

  int start_index = 5;
  for (int i = 0; i < len; i++) {
    padded_message[start_index] = message[i];
    start_index++;
  }

  printf("The padded message is: %s\n", padded_message);

  return 0;
}