//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  char message[100];
  printf("Sherlock Holmes: Hello, Watson. I have a task for you.\n");

  printf("Watson: Of course, what is it?\n");

  printf("Sherlock Holmes: I need you to help me solve a ransom note case. The kidnapper has sent a message to the victim's family with a list of demands.\n");
  
  printf("Watson: What do we need to do?\n");

  printf("Sherlock Holmes: We need to figure out which letters and symbols were used based on the words in the note. We will be using a greedy algorithm.\n");

  printf("Watson: A greedy algorithm?\n");

  printf("Sherlock Holmes: Yes, we will start with the most frequent letter in the message and match it to the most frequent letter in the English language. We will continue with the next most frequent letter until we have a match for each letter and symbol in the message.\n");

  printf("Watson: That sounds reasonable. Let's see what we have to work with.\n");

  printf("Sherlock Holmes: Here is the message: ");
  scanf("%[^\n]%*c", message);

  int frequency[256] = {0};
  int max_freq = 0, max_index = 0;

  for (int i = 0; message[i] != '\0'; i++) {
    if ('A' <= message[i] && message[i] <= 'Z') {
      ++frequency[message[i] - 'A' + 'a'];
    }
    ++frequency[message[i]];
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 'a'; j <= 'z'; j++) {
      if (frequency[j] > max_freq) {
        max_index = j;
        max_freq = frequency[j];
      }
    }
    printf("Sherlock Holmes: The letter %c in the message corresponds to the letter %c in the English language.\n", max_index, 'e' + i);
    frequency[max_index] = -1;
    max_index = max_freq = 0;
  }

  for (int i = ' '; i <= '/'; i++) {
    if (frequency[i] > max_freq) {
      max_index = i;
      max_freq = frequency[i];
    }
  }
  printf("Sherlock Holmes: The symbol %c in the message corresponds to the symbol %c in the English language.\n", max_index, ' ' + max_index - ' ');
  frequency[max_index] = -1;
  max_index = max_freq = 0;

  for (int i = ':'; i <= '@'; i++) {
    if (frequency[i] > max_freq) {
      max_index = i;
      max_freq = frequency[i];
    }
  }
  printf("Sherlock Holmes: The symbol %c in the message corresponds to the symbol %c in the English language.\n", max_index, ':' + max_index - ':');
  frequency[max_index] = -1;
  max_index = max_freq = 0;

  for (int i = '['; i <= '`'; i++) {
    if (frequency[i] > max_freq) {
      max_index = i;
      max_freq = frequency[i];
    }
  }
  printf("Sherlock Holmes: The symbol %c in the message corresponds to the symbol %c in the English language.\n", max_index, '[' + max_index - '[');
  frequency[max_index] = -1;
  max_index = max_freq = 0;

  for (int i = '{'; i <= '~'; i++) {
    if (frequency[i] > max_freq) {
      max_index = i;
      max_freq = frequency[i];
    }
  }
  printf("Sherlock Holmes: The symbol %c in the message corresponds to the symbol %c in the English language.\n", max_index, '{' + max_index - '{');
  frequency[max_index] = -1;

  printf("Watson: Impressive, Sherlock. We have successfully deciphered the message.\n");

  return 0;
}