//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef enum {
  TOK_INVALID,
  TOK_COLON,
  TOK_COMMA,
  TOK_STRING,
  TOK_NUMBER,
  TOK_TRUE,
  TOK_FALSE,
  TOK_NULL,
  TOK_LBRACE,
  TOK_RBRACE,
  TOK_LBRACKET,
  TOK_RBRACKET
} Token;

typedef struct {
  Token type;
  char *value;
} Tokenize;


static Tokenize *tokenize(char *str)
{
  Tokenize *toks;
  int i, len;
  char *p, *q;

  toks = malloc(sizeof(Tokenize) * MAX_LINE_LEN);
  if (!toks)
    return NULL;

  p = str;
  i = 0;
  while (*p) {
    while (*p && isspace(*p))
      p++;

    if (!*p)
      break;

    len = 0;
    q = p;
    while (q[len] && isspace(q[len]) == 0 &&
           q[len] != ':' && q[len] != ',' && q[len] != '{' &&
           q[len] != '}' && q[len] != '[' && q[len] != ']')
      len++;

    if (strncmp(q, ":", len) == 0) {
      toks[i].type = TOK_COLON;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (strncmp(q, ",", len) == 0) {
      toks[i].type = TOK_COMMA;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (strncmp(q, "{", len) == 0) {
      toks[i].type = TOK_LBRACE;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (strncmp(q, "}", len) == 0) {
      toks[i].type = TOK_RBRACE;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (strncmp(q, "[", len) == 0) {
      toks[i].type = TOK_LBRACKET;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (strncmp(q, "]", len) == 0) {
      toks[i].type = TOK_RBRACKET;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (strncmp(q, "true", len) == 0) {
      toks[i].type = TOK_TRUE;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (strncmp(q, "false", len) == 0) {
      toks[i].type = TOK_FALSE;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (strncmp(q, "null", len) == 0) {
      toks[i].type = TOK_NULL;
      toks[i].value = NULL;
      p += ++len;
      i++;
    } else if (q[0] == '"') {
      len++;
      p++;
      for (q = p; *q && q[len - 1] != '"'; len++, q++)
        ;
      if (*q == '"')
        len++;
      toks[i].type = TOK_STRING;
      toks[i].value = malloc(len);
      if (!toks[i].value)
        return NULL;
      memcpy(toks[i].value, p, len - 1);
      toks[i].value[len - 1] = '\0';
      p += len;
      i++;
    } else if (isdigit(*q) || (*q == '-' && isdigit(q[1]))) {
      for (q = p; *q && isdigit(*q) || *q == '.' || *q == 'e' ||
                 *q == 'E' || *q == '+' || *q == '-'; len++, q++)
        ;
      toks[i].type = TOK_NUMBER;
      toks[i].value = malloc(len + 1);
      if (!toks[i].value)
        return NULL;
      memcpy(toks[i].value, p, len);
      toks[i].value[len] = '\0';
      p += len;
      i++;
    } else {
      toks[i].type = TOK_INVALID;
      toks[i].value = NULL;
      p++;
      i++;
    }
  }

  toks[i].type = TOK_INVALID;
  toks[i].value = NULL;

  return toks;
}

static void free_toks(Tokenize *toks)
{
  int i;

  for (i = 0; toks[i].type != TOK_INVALID; i++)
    free(toks[i].value);

  free(toks);
}

int main(int argc, char *argv[])
{
  Tokenize *toks;
  int i, n;

  if (argc < 2) {
    printf("Usage: %s <json_file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  n = ftell(fp);
  rewind(fp);

  char *buf = malloc(n + 1);
  if (buf == NULL) {
    perror("malloc");
    fclose(fp);
    return 1;
  }

  fread(buf, 1, n, fp);
  buf[n] = '\0';
  fclose(fp);

  toks = tokenize(buf);
  if (toks == NULL) {
    perror("tokenize");
    free(buf);
    return 1;
  }

  for (i = 0; toks[i].type != TOK_INVALID; i++) {
    switch (toks[i].type) {
    case TOK_COLON:
      printf("COLON\n");
      break;
    case TOK_COMMA:
      printf("COMMA\n");
      break;
    case TOK_STRING:
      printf("STRING: %s\n", toks[i].value);
      break;
    case TOK_NUMBER:
      printf("NUMBER: %s\n", toks[i].value);
      break;
    case TOK_TRUE:
      printf("TRUE\n");
      break;
    case TOK_FALSE:
      printf("FALSE\n");
      break;
    case TOK_NULL:
      printf("NULL\n");
      break;
    case TOK_LBRACE:
      printf("LBRACE\n");
      break;
    case TOK_RBRACE:
      printf("RBRACE\n");
      break;
    case TOK_LBRACKET:
      printf("LBRACKET\n");
      break;
    case TOK_RBRACKET:
      printf("RBRACKET\n");
      break;
    default:
      printf("INVALID\n");
      break;
    }
  }

  free_toks(toks);
  free(buf);

  return 0;
}