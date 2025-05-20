#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
  char text[10000];
  printf("Enter text: ");
  fgets(text, 10000, stdin);

  // Calculate word frequency and context
  int words[1000] = {0};
  char context[100] = "";
  char* word_ptr = strtok(text, " ");
  while (word_ptr) {
    words[word_ptr - text] ++ ;
    context[word_ptr - text] = 1;
    word_ptr = strtok(NULL, " ");
  }

  // Prioritize words based on frequency and context
  int summary_length = 0;
  char summary[1000] = "";
  for (int i = 0; i < 1000; i++) {
    if (words[i] > 1 && context[i]) {
      sprintf(summary, "%s ", summary);
      summary_length++;
      if (summary_length >= 200) break;
    }
  }

  // Print summary
  if (summary_length) {
    printf("Summary:\n");
    printf("%s", summary);
  } else {
    printf("No summary could be generated.\n");
  }

  return 0;
}
