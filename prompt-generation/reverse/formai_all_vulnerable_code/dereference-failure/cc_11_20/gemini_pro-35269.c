//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style baby!

#define MAX_TOKEN_LEN 1024

enum token_type {
	TOK_NONE,
	TOK_STRING,
	TOK_NUMBER,
	TOK_BOOL,
	TOK_NULL,
	TOK_OBJECT_START,
	TOK_OBJECT_END,
	TOK_ARRAY_START,
	TOK_ARRAY_END,
	TOK_COLON,
	TOK_COMMA,
};

struct token {
	enum token_type type;
	char *value;
};

struct json_parser {
	char *input;
	int pos;
	int len;
	struct token token;
};

void json_parser_init(struct json_parser *parser, char *input)
{
	parser->input = input;
	parser->pos = 0;
	parser->len = strlen(input);
}

void json_parser_free(struct json_parser *parser)
{
	free(parser->token.value);
}

int json_parser_next_token(struct json_parser *parser)
{
	char *p;

	while (parser->pos < parser->len && isspace(parser->input[parser->pos]))
		parser->pos++;

	if (parser->pos >= parser->len)
		return TOK_NONE;

	p = parser->input + parser->pos;

	if (*p == '"') {
		parser->token.type = TOK_STRING;
		parser->token.value = malloc(MAX_TOKEN_LEN);
		int i = 0;
		while (*(++p) != '"') {
			if (*p == '\\') {
				p++;
				switch (*p) {
				case 'n':
					parser->token.value[i++] = '\n';
					break;
				case 'r':
					parser->token.value[i++] = '\r';
					break;
				case 't':
					parser->token.value[i++] = '\t';
					break;
				case 'f':
					parser->token.value[i++] = '\f';
					break;
				case 'b':
					parser->token.value[i++] = '\b';
					break;
				case '"':
					parser->token.value[i++] = '"';
					break;
				case '/':
					parser->token.value[i++] = '/';
					break;
				case '\\':
					parser->token.value[i++] = '\\';
					break;
				default:
					printf("Invalid escape sequence: %c\n", *p);
					return -1;
				}
				p++;
			} else {
				parser->token.value[i++] = *p;
			}
		}
		parser->token.value[i] = '\0';
		parser->pos = p - parser->input + 1;
	} else if (isdigit(*p) || *p == '-') {
		parser->token.type = TOK_NUMBER;
		parser->token.value = malloc(MAX_TOKEN_LEN);
		int i = 0;
		while (*p && (isdigit(*p) || *p == '.' || *p == 'e' || *p == 'E' || *p == '+' || *p == '-'))
			parser->token.value[i++] = *p++;
		parser->token.value[i] = '\0';
		parser->pos = p - parser->input;
	} else if (*p == 't' || *p == 'f') {
		parser->token.type = TOK_BOOL;
		parser->token.value = malloc(5);
		strcpy(parser->token.value, *p++ == 't' ? "true" : "false");
		parser->pos = p - parser->input;
	} else if (*p == 'n') {
		parser->token.type = TOK_NULL;
		parser->token.value = malloc(4);
		strcpy(parser->token.value, "null");
		parser->pos = p - parser->input + 4;
	} else if (*p == '{') {
		parser->token.type = TOK_OBJECT_START;
		parser->pos = p - parser->input + 1;
	} else if (*p == '}') {
		parser->token.type = TOK_OBJECT_END;
		parser->pos = p - parser->input + 1;
	} else if (*p == '[') {
		parser->token.type = TOK_ARRAY_START;
		parser->pos = p - parser->input + 1;
	} else if (*p == ']') {
		parser->token.type = TOK_ARRAY_END;
		parser->pos = p - parser->input + 1;
	} else if (*p == ':') {
		parser->token.type = TOK_COLON;
		parser->pos = p - parser->input + 1;
	} else if (*p == ',') {
		parser->token.type = TOK_COMMA;
		parser->pos = p - parser->input + 1;
	} else {
		printf("Invalid character: %c\n", *p);
		return -1;
	}

	return parser->token.type;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage: %s <json_string>\n", argv[0]);
		return -1;
	}

	struct json_parser parser;
	json_parser_init(&parser, argv[1]);

	while (json_parser_next_token(&parser) != TOK_NONE) {
		switch (parser.token.type) {
		case TOK_STRING:
			printf("String: %s\n", parser.token.value);
			break;
		case TOK_NUMBER:
			printf("Number: %s\n", parser.token.value);
			break;
		case TOK_BOOL:
			printf("Bool: %s\n", parser.token.value);
			break;
		case TOK_NULL:
			printf("Null\n");
			break;
		case TOK_OBJECT_START:
			printf("Object start\n");
			break;
		case TOK_OBJECT_END:
			printf("Object end\n");
			break;
		case TOK_ARRAY_START:
			printf("Array start\n");
			break;
		case TOK_ARRAY_END:
			printf("Array end\n");
			break;
		case TOK_COLON:
			printf("Colon\n");
			break;
		case TOK_COMMA:
			printf("Comma\n");
			break;
		default:
			printf("Unknown token\n");
			break;
		}
		free(parser.token.value);
	}

	json_parser_free(&parser);

	return 0;
}