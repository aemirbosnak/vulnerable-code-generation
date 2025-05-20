//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAPTERS 5
#define LINES_PER_PAGE 25
#define WORDS_PER_LINE 10

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <ebook file>\n", argv[0]);
    return 1;
  }

  // Read ebook file into memory
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  int file_size = ftell(fp);
  rewind(fp);

  char *ebook = malloc(file_size + 1);
  fread(ebook, 1, file_size, fp);
  fclose(fp);

  // Split ebook into chapters
  char *chapters[CHAPTERS];
  int chapter_lengths[CHAPTERS];

  int chapter_start = 0;
  int chapter_end = 0;

  for (int i = 0; i < CHAPTERS; i++) {
    chapter_end = strstr(ebook + chapter_start, "\n\n") - ebook;
    if (chapter_end == -1) {
      chapter_end = file_size;
    }

    chapters[i] = malloc(chapter_end - chapter_start + 1);
    memcpy(chapters[i], ebook + chapter_start, chapter_end - chapter_start);
    chapters[i][chapter_end - chapter_start] = '\0';

    chapter_lengths[i] = chapter_end - chapter_start;

    chapter_start = chapter_end + 2;
  }

  // Paginate chapters
  int page_count[CHAPTERS];
  int page_starts[CHAPTERS][LINES_PER_PAGE];

  for (int i = 0; i < CHAPTERS; i++) {
    page_count[i] = (chapter_lengths[i] + WORDS_PER_LINE - 1) / WORDS_PER_LINE / LINES_PER_PAGE;

    for (int j = 0; j < page_count[i]; j++) {
      page_starts[i][j] = j * WORDS_PER_LINE * LINES_PER_PAGE;
    }
  }

  // Display ebook
  int chapter_num = 0;
  int page_num = 0;

  while (1) {
    // Clear screen
    printf("\033[2J");

    // Display chapter and page number
    printf("Chapter %d, Page %d\n\n", chapter_num + 1, page_num + 1);

    // Display page
    int start = page_starts[chapter_num][page_num];
    int end = start + WORDS_PER_LINE * LINES_PER_PAGE;
    if (end > chapter_lengths[chapter_num]) {
      end = chapter_lengths[chapter_num];
    }

    for (int i = start; i < end; i++) {
      printf("%c", ebook[i]);
    }

    // Display page number
    printf("\n\nPage %d of %d", page_num + 1, page_count[chapter_num]);

    // Wait for user input
    int c = getchar();

    // Handle user input
    switch (c) {
    case 'q':
      return 0;
    case 'n':
      page_num++;
      if (page_num >= page_count[chapter_num]) {
        page_num = 0;
        chapter_num++;
      }
      break;
    case 'p':
      page_num--;
      if (page_num < 0) {
        page_num = page_count[chapter_num] - 1;
        chapter_num--;
      }
      break;
    case 'c':
      chapter_num++;
      if (chapter_num >= CHAPTERS) {
        chapter_num = 0;
      }
      page_num = 0;
      break;
    }
  }

  return 0;
}