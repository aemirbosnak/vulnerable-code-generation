//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#define SIZE 100
#define BUCKET_SIZE 5

char arr[SIZE];
int bins[BUCKET_SIZE][SIZE / BUCKET_SIZE + 1];

void initBins() {
  int i, j;
  for (i = 0; i < BUCKET_SIZE; i++) {
    for (j = 0; j < SIZE / BUCKET_SIZE + 1; j++) {
      bins[i][j] = -1;
    }
  }
}

int hash(char c) {
  return (int)c % BUCKET_SIZE;
}

void insert(int i, char c) {
  int j;
  if (bins[i][0] == -1) {
    bins[i][0] = c;
  } else {
    for (j = 0; j < SIZE / BUCKET_SIZE; j++) {
      if (bins[i][j + 1] == -1) {
        bins[i][j + 1] = c;
        break;
      }
    }
  }
}

void bucketSort(char *input) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    arr[i] = input[i];
  }

  initBins();

  for (i = 0; i < SIZE; i++) {
    insert(hash(arr[i]), arr[i]);
  }

  for (i = 0; i < BUCKET_SIZE; i++) {
    for (j = 0; j < SIZE / BUCKET_SIZE; j++) {
      if (bins[i][j] != -1) {
        input[i * (SIZE / BUCKET_SIZE) + j] = bins[i][j];
      }
    }
  }
}

int main() {
  char input[SIZE];
  int i;

  printf("Enter elements:\n");
  for (i = 0; i < SIZE; i++) {
    scanf("%c", &input[i]);
  }

  printf("Before Sorting: ");
  for (i = 0; i < SIZE; i++) {
    printf("%c ", input[i]);
  }
  printf("\n");

  bucketSort(input);

  printf("After Sorting: ");
  for (i = 0; i < SIZE; i++) {
    printf("%c ", input[i]);
  }
  printf("\n");

  return 0;
}