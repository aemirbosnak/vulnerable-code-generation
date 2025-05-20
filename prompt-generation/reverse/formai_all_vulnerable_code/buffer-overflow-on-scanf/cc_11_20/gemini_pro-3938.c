//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Welcome the user with a cheerful greeting!
  printf("Greetings, traveler! Welcome to the realm of string manipulation!\n");

  // Declare an array of characters, the playground for our string adventures.
  char adventure[100];

  // Prompt the user, the master string crafter, for their magical input.
  printf("Enter a string, your masterpiece, and let us unveil its wonders!\n");
  scanf(" %[^\n]", adventure);

  // Behold the length of the user's string, a testament to their creative prowess!
  int length = strlen(adventure);
  printf("The length of your string, a testament to your artistry, is: %d\n", length);

  // Time to reverse the string, turning it into its mirror image!
  char reversed[length + 1];
  int i, j;
  for (i = 0, j = length - 1; i < length; i++, j--) {
    reversed[i] = adventure[j];
  }
  reversed[length] = '\0'; // Don't forget the null terminator, the guardian of string boundaries!

  // Display the reversed string, a reflection of the user's original creation.
  printf("Behold, your string in reverse, a testament to your mastery:\n%s\n", reversed);

  // Now, let's count the vowels, the musical notes of the string!
  int vowelCount = 0;
  for (i = 0; i < length; i++) {
    char c = adventure[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      vowelCount++;
    }
  }

  // Announce the vowel count, a measure of the string's melodic richness.
  printf("Your string sings with %d vowels, a harmonious blend of sounds!\n", vowelCount);

  // Time for a twist! Let's find the longest word, the giant of the string.
  char *longestWord = NULL;
  int longestLength = 0;

  char *word = strtok(adventure, " "); // strtok, the trusty word dissector!

  while (word != NULL) {
    int wordLength = strlen(word);
    if (wordLength > longestLength) {
      longestWord = word;
      longestLength = wordLength;
    }

    word = strtok(NULL, " ");
  }

  // Behold the longest word, the titan among its brethren!
  printf("The mightiest word, the Goliath of your string, is: %s\n", longestWord);

  // But what if we want to remove a pesky substring, the thorn in the string's side?
  char substring[50];
  printf("Name the substring you wish to banish, the villain of your string:\n");
  scanf(" %s", substring);

  // Unleash strstr, the substring hunter, to find the villain's lair!
  char *found = strstr(adventure, substring);

  if (found != NULL) {
    // The villain is found! Time to erase its presence!
    int startIndex = found - adventure;
    int remainingLength = strlen(adventure) - startIndex - strlen(substring);
    memmove(adventure + startIndex, adventure + startIndex + strlen(substring),
             remainingLength + 1);

    // Victory! The substring is banished, its reign of terror over.
    printf("The substring, once a menacing presence, has been vanquished!\n");
  } else {
    // Alas, the substring remains elusive, a phantom in the string.
    printf("The substring, the elusive phantom, remains at large!\n");
  }

  // Finally, let's conclude our string adventure with a parting message.
  printf("Farewell, traveler! May your future string escapades be filled with joy and wonder!\n");

  return 0;
}