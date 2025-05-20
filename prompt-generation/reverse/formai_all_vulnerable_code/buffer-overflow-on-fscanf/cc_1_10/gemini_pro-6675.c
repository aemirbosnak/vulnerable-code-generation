//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define QR_MAX_SIZE 100

typedef struct {
  int size;
  int **matrix;
} QR;

QR *qr_new(int size) {
  QR *qr = malloc(sizeof(QR));
  qr->size = size;
  qr->matrix = malloc(sizeof(int *) * size);
  for (int i = 0; i < size; i++) {
    qr->matrix[i] = malloc(sizeof(int) * size);
  }
  return qr;
}

void qr_free(QR *qr) {
  for (int i = 0; i < qr->size; i++) {
    free(qr->matrix[i]);
  }
  free(qr->matrix);
  free(qr);
}

QR *qr_read(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  int size;
  fscanf(file, "%d", &size);

  QR *qr = qr_new(size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      fscanf(file, "%d", &qr->matrix[i][j]);
    }
  }

  fclose(file);

  return qr;
}

void qr_print(QR *qr) {
  for (int i = 0; i < qr->size; i++) {
    for (int j = 0; j < qr->size; j++) {
      printf("%d ", qr->matrix[i][j]);
    }
    printf("\n");
  }
}

bool qr_is_valid(QR *qr) {
  for (int i = 0; i < qr->size; i++) {
    for (int j = 0; j < qr->size; j++) {
      if (qr->matrix[i][j] < 0 || qr->matrix[i][j] > 255) {
        return false;
      }
    }
  }
  return true;
}

char qr_get_char(QR *qr, int x, int y) {
  if (x < 0 || x >= qr->size || y < 0 || y >= qr->size) {
    return ' ';
  }

  int value = qr->matrix[y][x];

  if (value < 32 || value > 126) {
    return ' ';
  }

  return (char)value;
}

char *qr_decode(QR *qr) {
  int size = qr->size;

  char *result = malloc(sizeof(char) * (size * size + 1));

  int index = 0;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result[index++] = qr_get_char(qr, j, i);
    }
  }

  result[index] = '\0';

  return result;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  const char *filename = argv[1];

  QR *qr = qr_read(filename);
  if (qr == NULL) {
    return 1;
  }

  if (!qr_is_valid(qr)) {
    fprintf(stderr, "Invalid QR code\n");
    qr_free(qr);
    return 1;
  }

  char *decoded = qr_decode(qr);
  printf("%s\n", decoded);

  free(decoded);
  qr_free(qr);

  return 0;
}