//Code Llama-13B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <errno.h>

  enum error_code {
    ERROR_NONE,
    ERROR_INVALID_INPUT,
    ERROR_FILE_NOT_FOUND,
    ERROR_READ_FAILED,
    ERROR_WRITE_FAILED,
    ERROR_UNKNOWN
  };

  struct error_message {
    int code;
    char* message;
  };

  struct error_message error_messages[] = {
    {ERROR_NONE, "No error"},
    {ERROR_INVALID_INPUT, "Invalid input"},
    {ERROR_FILE_NOT_FOUND, "File not found"},
    {ERROR_READ_FAILED, "Read failed"},
    {ERROR_WRITE_FAILED, "Write failed"},
    {ERROR_UNKNOWN, "Unknown error"}
  };

  void print_error(int code) {
    for (int i = 0; i < sizeof(error_messages) / sizeof(struct error_message); i++) {
      if (error_messages[i].code == code) {
        fprintf(stderr, "Error: %s\n", error_messages[i].message);
        return;
      }
    }
    fprintf(stderr, "Unknown error code: %d\n", code);
  }

  int main() {
    int error_code = ERROR_NONE;
    char* input = "input.txt";
    char* output = "output.txt";

    FILE* infile = fopen(input, "r");
    if (infile == NULL) {
      error_code = ERROR_FILE_NOT_FOUND;
      goto cleanup;
    }

    FILE* outfile = fopen(output, "w");
    if (outfile == NULL) {
      error_code = ERROR_WRITE_FAILED;
      goto cleanup;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), infile) != NULL) {
      if (fputs(buffer, outfile) == EOF) {
        error_code = ERROR_WRITE_FAILED;
        goto cleanup;
      }
    }

  cleanup:
    if (infile != NULL) {
      fclose(infile);
    }
    if (outfile != NULL) {
      fclose(outfile);
    }
    print_error(error_code);
    return error_code;
  }