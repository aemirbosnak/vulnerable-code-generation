//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char line[1024];
  regex_t regex;
  int reti;

  if (regcomp(&regex, "([0-9]{4})-([0-9]{2})-([0-9]{2}) ([0-9]{2}):([0-9]{2}):([0-9]{2}) ([A-Z]+) ([^ ]+) ([^ ]+)", REG_EXTENDED) != 0) {
    perror("regcomp");
    return EXIT_FAILURE;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    regmatch_t matches[8];
    reti = regexec(&regex, line, 8, matches, 0);
    if (reti == 0) {
      char date[11];
      char time[9];
      char level[8];
      char component[33];
      char message[1024];

      strncpy(date, line + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
      strncpy(time, line + matches[4].rm_so, matches[4].rm_eo - matches[4].rm_so);
      strncpy(level, line + matches[6].rm_so, matches[6].rm_eo - matches[6].rm_so);
      strncpy(component, line + matches[7].rm_so, matches[7].rm_eo - matches[7].rm_so);
      strncpy(message, line + matches[8].rm_so, matches[8].rm_eo - matches[8].rm_so);

      printf("%s %s %s %s %s\n", date, time, level, component, message);
    } else if (reti == REG_NOMATCH) {
      printf("No match found\n");
    } else {
      perror("regexec");
      return EXIT_FAILURE;
    }
  }

  fclose(fp);
  regfree(&regex);

  return EXIT_SUCCESS;
}